#!/bin/bash

# This script used to run tests on travis CI.

set -e

# Setup
BUILD_COMMAND="./build.sh -t ${TASK}"

if [[ -z "${COMPILLER}" ]]
then
    BUILD_COMMAND="${BUILD_COMMAND} -c ${COMPILLER}"
fi

# Run build and tests
if [[ "${TRAVIS_OS_NAME}" == "linux" ]]
then
    sudo docker run -it -v "${TRAVIS_BUILD_DIR}:/home/framework" alexiynew/docker_image bash -c "cd /home/framework/ && ${BUILD_COMMAND}"

    if [[ "${TASK}" == *"coverage"* ]]
    then
        bash <(curl -s https://codecov.io/bash)
    fi
elif [[ "${TRAVIS_OS_NAME}" == "osx" ]]
then
    "${BUILD_COMMAND}"
fi
