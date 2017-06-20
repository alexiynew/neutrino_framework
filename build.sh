#!/bin/bash

set -eu

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_DIR="$SCRIPT_DIR/build"

TASK_TO_RUN="none"

TEST_MODULES=""

# Settings functions

function set_compiler {
    local CC_COMPILER=
    local CXX_COMILLER=

    if [[ "$1" == "gcc" ]]
    then
        CC_COMPILER=gcc
        CXX_COMILLER=g++
    elif [[ "$1" == "clang" ]]
    then
        CC_COMPILER=clang
        CXX_COMILLER=clang++
    else
        echo -e "Unknown compiler: $1"
    fi

    echo -e "Specify C compiller as $CC_COMPILER."
    export CC="$CC_COMPILER"

    echo -e "Specify C++ compiller as $CXX_COMILLER."
    export CXX="$CXX_COMILLER"
}

# Task functions
function configure {
    echo -e ""
    echo -e "==== Run configuration ===="

    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DINCLUDED_TEST_MODULES=$TEST_MODULES ../
}

function build_framework {
    echo -e ""
    echo -e "==== Build framework ===="

    cd "$BUILD_DIR"
    make -j4 all
}

function build_tests {
    echo -e ""
    echo -e "==== Build framework tests ===="

    cd "$BUILD_DIR"
    make -j4 framework_tests
}

function install_all {
    echo -e ""
    echo -e "==== Install framework ===="

    cd "$BUILD_DIR"
    make install
}

function run_tests {
    echo -e ""
    echo -e "==== Run framework tests ===="

    cd "$BUILD_DIR"
    make run_all_tests
}

function run_tests_verbose {
    echo -e ""
    echo -e "==== Run framework tests verbose ===="

    cd "$BUILD_DIR"
    make run_all_tests_verbose
}

function coverage_scan {
    echo -e ""
    echo -e "==== Run test coverage scan ===="

    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DENABLE_TEST_COVERAGE=ON -DINCLUDED_TEST_MODULES=$TEST_MODULES ../

    make -j4 all

    make -j4 framework_tests

    make run_all_tests

    lcov --directory . --capture --output-file coverage.info                # capture coverage info
    lcov --remove coverage.info '/usr/*' --output-file coverage.info        # filter out system
    lcov --list coverage.info                                               # debug info

    echo -e "==== Uploading report to CodeCov ===="
    bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
}

function build_documentation {
    echo -e ""
    echo -e "==== Run framework tests verbose ===="

    cd "$BUILD_DIR"
    make documentation
}

function clean_all {
    echo -e ""
    echo -e "==== Clear all ===="

    cd "$SCRIPT_DIR"
    rm -rf ./output ./build
}

function print_help {
    echo -e ""
    echo -e "=== Help ==="
    echo -e "./build.sh [OPTION VALUE[,VALUE]]"
    echo -e ""
    echo -e "OPTIONS:"
    echo -e "\t -t : Specify task to run."
    echo -e "\t VALUES:"
    echo -e "\t\t configure    : Just runs cmake configuration."
    echo -e "\t\t build        : Build framework and tests."
    echo -e "\t\t install      : Install framework and tests."
    echo -e "\t\t test         : Run all tests."
    echo -e "\t\t test_verbose : Run all tests with verbose logging."
    echo -e "\t\t coverage     : Run test coverage scan."
    echo -e "\t\t docs         : Build documentation."
    echo -e "\t\t clean        : Clean build results."
    echo -e ""
    echo -e "\t -c : Specify compiller to use."
    echo -e "\t VALUES:"
    echo -e "\t\t gcc   : Use gcc compiller (default)."
    echo -e "\t\t clang : Use clang compiller."
    echo -e ""
    echo -e "\t -m : Specify which module you want to test."
    echo -e "\t\t Parameters: <module>[,<module>]"
    echo -e "\t\t If not present, all modules will be tested."
}

# Main logic

function run_task {
    case "$1" in
        "configure" )
            configure
        ;;
        "build" )
            configure
            build_framework
            build_tests
        ;;
        "install" )
            install_all
        ;;
        "test" )
            run_tests
        ;;
        "test_verbose" )
            run_tests_verbose
        ;;
        "coverage" )
            coverage_scan
        ;;
        "docs" )
            configure
            build_documentation
        ;;
        "clean" )
            clean_all
        ;;
        "none" )
            echo -e "You need to specify task."
            print_help
            exit 1
        ;;
        *) 
            echo -e "Unknown task '$1'"
            exit 1
        ;;
    esac
}

function execute {
    IFS=', ' read -r -a array <<< "$1"
    for task in "${array[@]}"; do
        run_task "$task"
    done
}

while getopts "t:c:m:h" opt; do
    case $opt in
        t)
            TASK_TO_RUN="$OPTARG"
        ;;
        c)
            set_compiler "$OPTARG"
        ;;
        m)
            TEST_MODULES="$OPTARG"
        ;;
        h)
            print_help
            exit 0
        ;;
        \?)
            echo -e "Invalid option -$OPTARG."
            print_help
            exit 1
        ;;
        :)
            echo -e "Option -$OPTARG requires an argument."
            print_help
            exit 1
        ;;
    esac
done

execute "$TASK_TO_RUN"
