#!/bin/sh

set -ue

# @todo #78:30min Add c++ style checker
#  This may be cpplint or cppcheck for example.

# Scan sources for wrong pdd tokens
pdd > /dev/null
