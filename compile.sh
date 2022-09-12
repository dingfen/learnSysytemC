#!/bin/sh

if [ ! -d "build" ]; then
    mkdir build
fi

if [ ! -d "log" ]; then
    mkdir log
fi

cd build

cmake -DCMAKE_BUILD_TYPE=Debug ..  

make

cd ..