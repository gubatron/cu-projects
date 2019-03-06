cmake_minimum_required(VERSION 2.8)
project(bstRecitation)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
    driver.cpp
        BST.cpp
    )

add_executable(bstRecitation ${SOURCE_FILES})
