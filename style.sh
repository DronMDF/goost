#!/bin/sh

set -ue

cppcheck -I. --enable=all --suppress=missingIncludeSystem --suppress=useStlAlgorithm --quiet --error-exitcode=1 goost test

cpplint `for d in benchmark goost test; do find $d -name *.cpp -o -name *.h; done`
