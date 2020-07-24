cmake_minimum_required(VERSION 2.8)
project(ht_chaining.exe)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
hashchain.cpp
hashchaindriver.cpp
)

add_executable(ht_chaining.exe ${SOURCE_FILES})