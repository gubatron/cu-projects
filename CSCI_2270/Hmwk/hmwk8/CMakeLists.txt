cmake_minimum_required(VERSION 2.8)
project(priorityqueue)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
        priorityQueue.cpp
        )

add_executable(priorityqueue ${SOURCE_FILES})
