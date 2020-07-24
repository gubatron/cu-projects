#!/bin/bash
if [ -f std_map.exe ]; then
    rm std_map.exe
fi
echo "Building std_map..."
g++ -std=c++11 stdmapdriver.cpp -o std_map.exe
if [ $? -ne 0 ]; then
    echo "Error building std_map"
    exit 1
fi
