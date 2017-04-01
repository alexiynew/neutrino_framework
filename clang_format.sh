#!/usr/bin/env bash

FILES=`find ./src ./test -iregex ".*\(cpp\|h\|hpp\)" -type f | sort`

for FILE in ${FILES}
do
  echo ${FILE}
  clang-format-4.0 -style=file -i ${FILE}
done
