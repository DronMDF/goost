#!/bin/sh

set -ue

# @todo #340 Add benchmark dir to style check (after rework)
cppcheck -I. --enable=all --suppress=missingIncludeSystem --quiet magma kuznyechik test2o

./cpplint.py `for d in magma kuznyechik benchmark test2o; do find $d -name *.cpp -o -name *.h | grep -v upp11.h; done`

# Scan sources for wrong pdd tokens
pdd > /dev/null
