#!/bin/bash
g++ -std=c++11 dll.cpp dlldriver.cpp -o doubly_linked_list.exe
if [ $? -ne 0 ]; then
    echo "Error building doubly_linked_list"
    exit 1
fi
