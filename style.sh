#!/bin/sh

set -ue

# @todo #340 Add benchmark dir to style check (after rework)
cppcheck -I. --enable=all --suppress=missingIncludeSystem --quiet benchmark goost test

cpplint `for d in benchmark goost test; do find $d -name *.cpp -o -name *.h; done`

# Scan sources for wrong pdd tokens
pdd > /dev/null
