cmake_minimum_required(VERSION 3.13)
project(CSCI2270)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSCI2270
        Labs/lab1/hello.cpp
        Lectures/lecture3/arrays.cpp
        Lectures/lecture3/file_input.cpp
        Lectures/lecture3/file_input_line_by_line.cpp
        Lectures/lecture3/file_output_and_append.cpp
        Lectures/lecture3/input_from_keyboard.cpp
        Lectures/lecture3/pointer_variables.cpp
        Lectures/lecture3/structures.cpp Labs/lab1/commandLine.cpp Labs/lab1/function.h Labs/lab1/funcdef.cpp Labs/lab1/main.cpp Labs/lab1/oFile.cpp Labs/lab1/iFile.cpp Hmwk/hmwk1/insertIntoSortedArray.cpp Hmwk/hmwk1/userGPA_withStruct.cpp Lectures/lecture4/factorial_factorialRecrusion.cpp Lectures/quiztest.cpp Hmwk/hmwk2/wordAnalysis.cpp Labs/rec3/dynamicMemory_linkedLists.cpp "Lectures/Array Lists/DynamicarrayList.cpp" "Lectures/Array Lists/FixedArrayList.cpp")
