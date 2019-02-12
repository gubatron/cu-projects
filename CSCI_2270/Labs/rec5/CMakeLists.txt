cmake_minimum_required(VERSION 2.8)
project(rec5)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(rec5 Driver.cpp DriverQueue.cpp)
