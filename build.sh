#!/bin/sh

mkdir -p build/
cmake -B build/ -G "Unix Makefiles"
cmake --build build/
