#! /bin/bash

FILES=`find ./framework ./test -iregex ".*\(c\|cpp\|m\|mm\|h\|hpp\)" -type f | sort`

clang-format -style=file -i ${FILES}
