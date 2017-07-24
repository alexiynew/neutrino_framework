#!/bin/bash

# This script used to run tests on travis CI.

set -e

# Run build and tests
if [[ "${TRAVIS_OS_NAME}" == "linux" ]]
then
    sudo docker run -it -v "${TRAVIS_BUILD_DIR}:/home/framework" alexiynew/docker_image bash -c "/home/framework/build.sh -t ${TASK} -c ${COMPILLER}"

    if [[ "${TASK}" == *"coverage"* ]]
    then
        bash <(curl -s https://codecov.io/bash)
    fi
elif [[ "${TRAVIS_OS_NAME}" == "osx" ]]
then
    ./build.sh -t "${TASK}"
fi
