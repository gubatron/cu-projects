# What is this? This is a cmake file to create a Makefile with minimum effort
#
# Usage:
#    To create make file type: `cmake .`
# Once `Makefile` has been created:
#    build with: `make`
#    clean with: `make clean`
#
cmake_minimum_required(VERSION 3.8)
project(hmwk9 CXX)

set(SOURCE_FILES
        Supply.h
        Milestone.cpp
        Servo.cpp
        Player.cpp
        Game.cpp
        )

if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
    add_compile_options(
            -Weverything
            -Wno-c++98-compat
            -Wno-padded
            -Wno-global-constructors
            -Wno-exit-time-destructors
            -Wno-weak-vtables
            -Wundefined-func-template)
endif ()
set(CMAKE_BUILD_TYPE Debug)
add_executable(hmwk9 ${SOURCE_FILES})
set_target_properties(hmwk9 PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(hmwk9 PUBLIC cxx_std_11)