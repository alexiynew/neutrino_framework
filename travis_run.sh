#!/bin/bash

# This script used to run tests on travis CI.

set -e

if [[ "${TRAVIS_OS_NAME}" == "linux" ]]
then
    # Run build and tests
    sudo docker run -it -v "${TRAVIS_BUILD_DIR}:/home/framework" alexiynew/docker_image bash -c "/home/framework/build.sh -c $COMPILLER -t $TASK"

    if [[ "${TASK}" == *"coverage"* ]]
    then
        bash <(curl -s https://codecov.io/bash)
    fi
elif [[ "${TRAVIS_OS_NAME}" == "osx" ]]
then
    "${TRAVIS_BUILD_DIR}"/build.sh -c $COMPILLER -t $TASK
fi
