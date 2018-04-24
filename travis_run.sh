#!/bin/bash

# This script used to run tests on travis CI.

set -e

# Run build and tests
if [[ "${TRAVIS_OS_NAME}" == "linux" ]]
then
    WORKDIR="/home/framework"
    RUN_COMMAND="./build.sh -c ${COMPILLER} ${TASK}"
    sudo docker run -it -e COMMAND="${RUN_COMMAND}" -w "${WORKDIR}" -v "${TRAVIS_BUILD_DIR}:${WORKDIR}" alexiynew/docker_image 

    if [[ "${TASK}" == *"coverage"* ]]
    then
        bash <(curl -s https://codecov.io/bash)
    fi
elif [[ "${TRAVIS_OS_NAME}" == "osx" ]]
then
    ./build.sh "${TASK}"
fi
