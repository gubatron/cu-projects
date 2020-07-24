#!/bin/bash
echo "Building ht_quadratic_probing..."
g++ -std=c++11 hashquad.cpp hashquaddriver.cpp -o ht_quadratic_probing.exe
if [ $? -ne 0 ]; then
    echo "Error building ht_quadratic_probing"
    exit 1
fi
