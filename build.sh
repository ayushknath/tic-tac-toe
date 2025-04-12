#!/bin/bash

if [ -d "build" ]; then
    echo "Build folder exists"
else
    mkdir build
fi

cd build
cmake -G "Ninja" ..
cmake --build .

if [ $? -ne 0 ]; then
    echo "CMake encountered some error!"
fi