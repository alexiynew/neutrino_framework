#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

set -e

CC_COMPILER=gcc
CXX_COMILLER=g++

function set_compiler {
    if [ "$1" == "gcc" ]
    then
        CC_COMPILER=gcc
        CXX_COMILLER=g++
    elif [ "$1" == "clang" ]
    then
        CC_COMPILER=clang
        CXX_COMILLER=clang++
    else
        echo "Unknown compiler: $1" >&2
    fi

    echo "Specify C compiller as $CC_COMPILER." >&2
    export CC=$CC_COMPILER

    echo "Specify C++ compiller as $CXX_COMILLER." >&2
    export CXX=$CXX_COMILLER
}

while getopts ":c:" opt; do
    case $opt in
        c)
            set_compiler $OPTARG >&2
        ;;
        \?)
            echo "Invalid option -$OPTARG." >&2
            exit 1
        ;;
        :)
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
        ;;
    esac
done


cd $SCRIPT_DIR
echo "Start build in $(pwd)"

mkdir -p build && cd ./build

cmake -DCMAKE_BUILD_TYPE=Release ../

make -j4 all
make CreateTestSuiteExecutable
