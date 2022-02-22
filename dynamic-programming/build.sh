#!/usr/bin/env bash

set -xe

CC=g++
CFLAGS="-std=c++17 -Wall -Wextra -g3 -o3"
LS="exa -d */ -1"

for dir in $($LS); do
    for file in ./$dir/*.cpp; do
        echo "$file"
        $CC $CFLAGS "$file" -o "${file%.cpp}.out"
    done
done
