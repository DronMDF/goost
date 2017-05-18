#!/bin/sh

set -ue

# @todo #80:15min Add cpplynt for check project
cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet .

# Scan sources for wrong pdd tokens
pdd > /dev/null
