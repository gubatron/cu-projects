#!/bin/bash
echo "Building ht_linear_probing..."
g++ -std=c++11 hashlinear.cpp hashlineardriver.cpp -o ht_linear.exe
if [ $? -ne 0 ]; then
    echo "Error building ht_linear"
    exit 1
fi
