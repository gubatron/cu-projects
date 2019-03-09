cmake_minimum_required(VERSION 2.8)
project(movietreehw6)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
    MovieTree.cpp
    )

add_executable(movietreehw6 ${SOURCE_FILES})
