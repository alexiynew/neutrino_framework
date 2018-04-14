#!/bin/bash

# This script used to run tests on travis CI.

set -e

# Run build and tests
if [[ "${TRAVIS_OS_NAME}" == "linux" ]]
then
    COMMAND="xvfb-run -a -s \"-screen 0 1024x768x24\" /home/framework/build.sh -c ${COMPILLER} ${TASK}"
    sudo docker run -it -v "${TRAVIS_BUILD_DIR}:/home/framework" alexiynew/docker_image bash -c "${COMMAND}"

    if [[ "${TASK}" == *"coverage"* ]]
    then
        bash <(curl -s https://codecov.io/bash)
    fi
elif [[ "${TRAVIS_OS_NAME}" == "osx" ]]
then
    ./build.sh "${TASK}"
fi
