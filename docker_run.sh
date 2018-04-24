#!/bin/bash

# This script works inside docker container

export DISPLAY=:1
Xorg -noreset +extension GLX +extension RANDR +extension RENDER -logfile ./Xdummy.log -config /xorg.conf :1 &> /dev/null &

openbox &

bash -c "${COMMAND}"
