#!/bin/bash

# This script used to run tests in docker environment

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $SCRIPT_DIR

# Setup virtual display
Xvfb :1 -screen 0 1024x768x16 &> xvfb.log &
export DISPLAY=:1.0

# Run build and tests
./build.sh -c $COMPILLER -t $TASK
