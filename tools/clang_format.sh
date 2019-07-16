#! /bin/bash

FILES=`find ./neutrino ./test -iregex ".*\(c\|cpp\|m\|mm\|h\|hpp\)" -type f | sort`

clang-format -style=file -i ${FILES}
