#!/bin/bash

# This script used to run tests in docker environment

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$SCRIPT_DIR"

# Run build and tests
sudo docker run -it -v "$(pwd):/home/framework" alexiynew/docker_image bash -c "/home/framework/build.sh -c $COMPILLER -t $TASK"

if [[ "${TASK}" == *"coverage"* ]]
then
    bash <(curl -s https://codecov.io/bash)
fi
