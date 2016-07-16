#!/bin/bash

# Debug
#set -ev

parent_path=$( cd "$(dirname "${BASH_SOURCE}")" ; pwd -P )
cd $parent_path

if [ -f "../test/build/debug/maxheap_testd" ]; then
     ./../test/build/debug/maxheap_testd
fi

if [ -f "../test/build/release/maxheap_test" ]; then
     ./../test/build/release/maxheap_test
fi
