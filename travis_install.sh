#!/bin/bash

# This script used to setup docker on travis CI.

set -e

if [[ "${TRAVIS_OS_NAME}" == "linux" ]]
then
    docker pull alexiynew/docker_image
fi
