#!/bin/bash

echo "Start build in "$(pwd)
mkdir -p build && cd ./build

cmake -DCMAKE_BUILD_TYPE=Release ../

make -j4 all
make CreateTestSuiteExecutable
