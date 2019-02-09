cmake_minimum_required(VERSION 2.8)
project(CountryNetwork)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#indicate the entry point for the executable
add_executable(CountryNetwork main.cpp CountryNetwork.cpp)
