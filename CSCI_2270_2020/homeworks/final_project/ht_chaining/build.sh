#!/bin/bash
if [ -f ht_chaining.exe ]; then
    rm ht_chaining.exe
fi
echo "Building ht_chaining..."
g++ -std=c++11 hashchain.cpp hashchaindriver.cpp -o ht_chaining.exe
if [ $? -ne 0 ]; then
    echo "Error building ht_chaining"
    exit 1
fi
