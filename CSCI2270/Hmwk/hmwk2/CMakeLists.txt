cmake_minimum_required (VERSION 2.8)
project (wordAnalysis)

#version number
set (CMAKE_CXX_STANDARD 11)

#indicate the entry point for the executable
add_executable (wordAnalysis wordAnalysis.cpp)