#!/bin/sh

set -ue

cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet magma kuznyechik test test2o

# @todo #117:15min Add include files to cpplint processing
./cpplint.py `for d in magma kuznyechik test test2o; do find $d -name *.cpp; done`

# Scan sources for wrong pdd tokens
pdd > /dev/null
