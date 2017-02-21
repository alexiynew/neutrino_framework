#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

set -e

CC_COMPILER=gcc
CXX_COMILLER=g++

TASK_TO_RUN=none

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
        echo "Unknown compiler: $1"
    fi

    echo "Specify C compiller as $CC_COMPILER."
    export CC=$CC_COMPILER

    echo "Specify C++ compiller as $CXX_COMILLER."
    export CXX=$CXX_COMILLER
}

function build {
    cd $SCRIPT_DIR
    echo "==== Start build in $(pwd) ===="
    mkdir -p build && cd ./build
    cmake -DCMAKE_BUILD_TYPE=Release ../

    echo ""
    echo "==== Build framework ===="
    make -j4
    make install

    echo ""
    echo "==== Build framework tests ===="
    make -j4 framework_tests
    cd $SCRIPT_DIR
}

function run_tests {
    cd $SCRIPT_DIR
    echo "==== Run framework tests ===="
    cd ./build
    make run_all_tests
    cd $SCRIPT_DIR
}

function run_tests_verbose {
    cd $SCRIPT_DIR
    echo "==== Run framework tests verbose ===="
    cd ./build
    make run_all_tests_verbose
    cd $SCRIPT_DIR
}

function clean_all {
    cd $SCRIPT_DIR
    rm -rf ./output ./build
}

function print_help {
    echo -e "=== Help ==="
    echo -e "./build.sh [OPTION VALUE] [OPTION VALUE]"
    echo -e "OPTIONS:"
    echo -e "\t -t : Specify task to run."
    echo -e "\t VALUES:"
    echo -e "\t\t build        : Build and install framework, also build tests."
    echo -e "\t\t test         : Run all tests."
    echo -e "\t\t test_verbose : Run all tests with verbose logging."
    echo -e "\t\t clean        : Clean build results."
    echo -e "\t -c : Specify compiller to use."
    echo -e "\t VALUES:"
    echo -e "\t\t gcc   : Use gcc compiller (default)."
    echo -e "\t\t clang : Use clang compiller."
}

function run_task {
    case "$1" in
        "build" )
            build
        ;;
        "test" )
            run_tests
        ;;
        "test_verbose" )
            run_tests_verbose
        ;;
        "clean" )
            clean_all
        ;;
        "none" )
            echo "You need to specify task."
            print_help
            exit 1
        ;;
    esac
}

while getopts "t:c:" opt; do
    case $opt in
        c)
            set_compiler $OPTARG
        ;;
        t)
            TASK_TO_RUN=$OPTARG
        ;;
        \?)
            echo "Invalid option -$OPTARG."
            print_help
            exit 1
        ;;
        :)
            echo "Option -$OPTARG requires an argument."
            print_help
            exit 1
        ;;
    esac
done

run_task $TASK_TO_RUN
