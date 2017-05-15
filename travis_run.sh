#!/bin/bash

# This script used to run tests in docker environment

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $SCRIPT_DIR

echo -e "Setup virtual display"
Xvfb :1 -screen 0 1024x768x16 &> xvfb.log &
echo -e "Setup virtual display 1"
ps aux | grep X
echo -e "Setup virtual display 2"
export DISPLAY=:1.0
echo -e "Setup virtual display 3"

echo -e "Run build and tests"
./build.sh -c $COMPILLER -t clean,build,test
