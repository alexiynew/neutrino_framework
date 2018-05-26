#! /bin/bash

FILES=`find ./src ./test -iregex ".*\(c\|cpp\|h\|hpp\|m\|mm\)" -type f | sort`
ctags -u --c++-kinds=+pzxlN --fields=+kntiaS --extras=+q ${FILES}
