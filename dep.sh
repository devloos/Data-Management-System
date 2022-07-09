#!/bin/bash

cd lib

git clone https://github.com/mongodb/mongo-c-driver.git
cd mongo-c-driver
git checkout 1.21.2
mkdir cmake-build
cd cmake-build
cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..
if [[ "$OSTYPE" =~ ^msys ]]; then
    sudowin cmake --build . --target install
else
    sudo cmake --build . --target install
fi

cd ../../
rm -rf mongo-c-driver*
tar -xf mongo-cxx-driver-r3.6.7.tar.gz
cd mongo-cxx-driver-r3.6.7/build
cmake ..                                \
    -DCMAKE_BUILD_TYPE=Release          \
    -DBSONCXX_POLY_USE_MNMLSTC=1        \
    -DCMAKE_INSTALL_PREFIX=/usr/local
if [[ "$OSTYPE" =~ ^msys ]]; then
    sudowin cmake --build . --target install
else
    sudo cmake --build . --target install
fi
cd ../../
rm -rf mongo-cxx-driver-r3.6.7*

tar -xf ncurses-6.3.tar.gz
cd ncurses-6.3/
./configure
make
if [[ "$OSTYPE" =~ ^msys ]]; then
    sudowin make install
else
    sudo make install
fi

cd ../
rm -rf ncurses-6.3*