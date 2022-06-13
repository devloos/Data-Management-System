#!/bin/bash

git clone https://github.com/mongodb/mongo-c-driver.git
cd mongo-c-driver
git checkout 1.21.2
mkdir cmake-build
cd cmake-build
cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..
sudo cmake --build . --target install

cd ../../
rm -rf mongo-c-driver*
curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.6.7/mongo-cxx-driver-r3.6.7.tar.gz
tar -xzf mongo-cxx-driver-r3.6.7.tar.gz
cd mongo-cxx-driver-r3.6.7/build
cmake ..                                \
    -DCMAKE_BUILD_TYPE=Release          \
    -DBSONCXX_POLY_USE_MNMLSTC=1        \
    -DCMAKE_INSTALL_PREFIX=/usr/local
sudo cmake --build . --target install
rm -rf mongo-cxx-driver-r3.6.7*
rm mongo-cxx-driver-r3.6.7.tar.gz
