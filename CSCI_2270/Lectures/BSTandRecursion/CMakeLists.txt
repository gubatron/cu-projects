cmake_minimum_required(VERSION 2.8)
project(bstRecursion)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
    bstRecursion.cpp
    )

add_executable(bstRecursion ${SOURCE_FILES})
