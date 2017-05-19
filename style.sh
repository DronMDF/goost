#!/bin/sh

set -ue

cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet .

# @todo #117:15min Add include files to cpplint processing
./cpplint.py `find ./ -name *.cpp`

# Scan sources for wrong pdd tokens
pdd > /dev/null
