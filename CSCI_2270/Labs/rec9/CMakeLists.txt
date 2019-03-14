cmake_minimum_required(VERSION 2.8)
project(hash)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
        hash.cpp
        driver.cpp
        )

add_executable(hash ${SOURCE_FILES})
