#!/bin/sh

set -ue

# cppcheck 1.82 (from github action) make false positive and not support useStlAlgorithm
# --suppress=useStlAlgorithm --error-exitcode=1
# Use it for information
cppcheck -I. --enable=all --suppress=missingIncludeSystem --quiet goost test

cpplint `for d in benchmark goost test; do find $d -name *.cpp -o -name *.h; done`
