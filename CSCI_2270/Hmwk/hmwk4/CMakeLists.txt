cmake_minimum_required(VERSION 2.8)
project(rpncalc)

#version number
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#the sources for our executable
set(SOURCE_FILES
    RPNCalculator.cpp
    RPNCalculatorDriver.cpp
    ProducerConsumer.cpp
    ProducerCOnsumerDriver.cpp
    )

add_executable(rpncalc ${SOURCE_FILES})
