#!/bin/bash

# This script used to run tests on travis CI.

set -e

# Run build and tests
WORKDIR="/home/framework"
RUN_COMMAND="meson build && ninja -C build ${TASK}"
sudo docker run -it -e COMMAND="${RUN_COMMAND}" -e CC="${CC_COMPILER}" -e CXX="${CXX_COMPILER}" -w "${WORKDIR}" -v "${TRAVIS_BUILD_DIR}:${WORKDIR}" alexiynew/docker_image 

if [[ "${TASK}" == *"coverage"* ]]
then
    bash <(curl -s https://codecov.io/bash)
fi
