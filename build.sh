#!/bin/bash

echo "Start build in "$(pwd) 
mkdir -p build
cd ./build 
echo $(pwd)

cmake ../
make all 
make CreateTestSuiteExecutable
