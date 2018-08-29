#!/usr/bin/env bash

FILES=`find ./src ./test -iregex ".*\(c\|cpp\|h\|hpp\|m\|mm\)" -type f | sort`

for FILE in ${FILES}
do
  echo ${FILE}
  clang-format -style=file -i ${FILE}
done
