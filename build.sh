#!/usr/bin/env bash

set -eu

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
BUILD_DIR="$SCRIPT_DIR/build"

TASK_TO_RUN=""

TEST_MODULES=""

BUILD_TYPE="Debug"

GENERATOR=""

RED='\033[0;31m'
BLUE='\033[0;34m'
LIGHT_CYAN='\e[1;36m'
NO_COLOR='\033[0m'

function info {
    echo -e "${LIGHT_CYAN}$1${NO_COLOR}";
}

function error {
    echo -e "${RED}$1${NO_COLOR}";
}

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
        error "Unknown compiler: '$1'."
        exit 1
    fi

    info "Specify C compiller as $CC_COMPILER."
    export CC="$CC_COMPILER"

    info "Specify C++ compiller as $CXX_COMILLER."
    export CXX="$CXX_COMILLER"
}

function check_x11_support {
    if [[ "$(uname -s)" == "Linux" ]]
    then
        if [[ -n ${DISPLAY+x} ]]
        then
            info "==== Found existing display ===="
        else
            info "==== Setup virtual display ===="

            Xvfb :1 -screen 0 1024x768x16 &> .xvfb.log &
            export DISPLAY=:1.0
        fi
    fi
}

function set_generator {
    if [[ "$(uname -s)" == "Linux" ]]
    then
        GENERATOR="Unix Makefiles"
    elif [[ "$(uname -s)" == "Darwin" ]]
    then
        GENERATOR="Xcode"
    fi
}

# Task functions
function configure {
    info "==== Run configuration ===="

    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    cmake  -G "$GENERATOR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE" -DBUILD_TESTS=ON -DINCLUDED_TEST_MODULES="$TEST_MODULES" ../
}

function build_framework {
    info "==== Build framework ===="

    cd "$BUILD_DIR"
    make -j4 all
}

function build_tests {
    info "==== Build framework tests ===="

    cd "$BUILD_DIR"
    make -j4 framework_tests
}

function install_all {
    info "==== Install framework ===="

    cd "$BUILD_DIR"
    make install
}

function run_tests {
    info "==== Run framework tests ===="

    check_x11_support

    cd "$BUILD_DIR"
    make run_all_tests
}

function run_tests_verbose {
    info "==== Run framework tests verbose ===="

    check_x11_support

    cd "$BUILD_DIR"
    make run_all_tests_verbose
}

function coverage_scan {
    info "==== Run test coverage scan ===="

    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"

    cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DENABLE_TEST_COVERAGE=ON -DINCLUDED_TEST_MODULES="$TEST_MODULES" ../

    build_framework

    build_tests

    run_tests

    info "==== Get lcov report ===="
    lcov --directory . --capture --output-file coverage.info                # capture coverage info
    lcov --remove coverage.info '/usr/*' --output-file coverage.info        # filter out system
    lcov --list coverage.info                                               # debug info
}

function run_check {
    info "==== Run CppCheck ===="

    files=`find ./src ./test -iregex ".*\(cpp\|h\|hpp\)" -type f | sort`

    cppcheck --enable=all -I./src ${files}

    info "==== Run clang scan-build ===="

    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"

    scan-build cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -DINCLUDED_TEST_MODULES="$TEST_MODULES" ../
    scan-build make all
    scan-build make framework_tests
}

function build_documentation {
    info "==== Run framework tests verbose ===="

    cd "$BUILD_DIR"
    make documentation
}

function clean_all {
    info "==== Clear all ===="

    cd "$SCRIPT_DIR"
    rm -rf ./output ./build
}

function print_help {
cat << EOF
==== Help ====
    ./build.sh [OPTION VALUE] [ACTION [ACTION]]

    OPTIONS:
        ACTIONS:
            configure    : Just runs cmake configuration.
            build        : Build framework and tests.
            install      : Install framework and tests.
            test         : Run all tests.
            test_verbose : Run all tests with verbose logging.
            coverage     : Run test coverage scan.
            check        : Run static analizers.
            docs         : Build documentation.
            clean        : Clean build results.

        -b : Specify build type.
        VALUES:
            debug   : Debug build (default).
            release : Release build.

        -c : Specify compiller to use.
        VALUES:
            gcc   : Use gcc compiller (default).
            clang : Use clang compiller.

        -m : Specify which module you want to test.
        Parameters: <regex>
            If not present, all modules will be tested.
EOF
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
            configure
            run_tests
        ;;
        "test_verbose" )
            configure
            run_tests_verbose
        ;;
        "coverage" )
            coverage_scan
        ;;
        "check" )
            run_check
        ;;
        "docs" )
            configure
            build_documentation
        ;;
        "clean" )
            clean_all
        ;;
        "none" )
            error "You need to specify task."
            print_help
            exit 1
        ;;
        *)
            error "Unknown task '$1'."
            exit 1
        ;;
    esac
}

function execute {
    IFS=', ' read -r -a array <<< "$1"
    for task in "${array[@]}"
    do
        run_task "$task"
    done
}

function parse_argument {
    option="$1"
    value="$2"

    if [[ "$value" == "" ]]
    then
        error "Option '$option' requires an argument."
        exit 1
    fi

    case "$option" in
        -b)
            BUILD_TYPE="$value"
        ;;
        -c)
            set_compiler "$value"
        ;;
        -m)
            TEST_MODULES="$value"
        ;;
        *)
            error "Unknown option '$option'."
            exit 1
        ;;
    esac
}

args_count=$#
for (( index=1; index<=args_count; index++))
do
    arg="${!index}"
    case "$arg" in
        -h)
            print_help
            exit 0
        ;;
        -* )
            next_index=$((index+1))

            if [[ "$next_index" -gt "$args_count" ]]
            then
                error "Option '$arg' requires an argument."
                exit 1
            fi

            next_arg="${!next_index}"
            parse_argument "$arg" "$next_arg"

            index=next_index
        ;;
        *)
            TASK_TO_RUN="$TASK_TO_RUN $arg"
        ;;
    esac
done

set_generator
execute "$TASK_TO_RUN"
