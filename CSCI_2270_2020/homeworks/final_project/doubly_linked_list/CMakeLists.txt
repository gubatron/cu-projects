cmake_minimum_required(VERSION 2.8)
project(doubly_linked_list.exe)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
dll.cpp
dlldriver.cpp
)

add_executable(doubly_linked_list.exe ${SOURCE_FILES})