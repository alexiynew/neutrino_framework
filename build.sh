#!/bin/bash

if [ -z "$CC" ]; then
    echo "Specify C compiller as clang."
    export CC=clang
fi

if [ -z "$CXX" ]; then
    echo "Specify C++ compiller as clang++."
    export CXX=clang++
fi

echo "Start build in "$(pwd)
mkdir -p build && cd ./build

cmake -DCMAKE_BUILD_TYPE=Release ../

make -j4 all
make CreateTestSuiteExecutable
