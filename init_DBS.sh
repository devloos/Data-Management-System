#!/bin/bash

git clone https://github.com/mongodb/mongo-c-driver.git
cd mongo-c-driver
git checkout 1.21.2
mkdir cmake-build
cd cmake-build
cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..
sudo cmake --build . --target install
