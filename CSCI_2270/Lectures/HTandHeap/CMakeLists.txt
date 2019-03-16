cmake_minimum_required(VERSION 2.8)
project(hashtable)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
        hashTableChaining.cpp
        hashTableLinearProbing.cpp
        driverMaxHeap.cpp
        driverMinHeap.cpp
        )

add_executable(hashtable ${SOURCE_FILES})
