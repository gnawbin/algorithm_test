cmake_minimum_required(VERSION 3.28)
project(algorithm_test)

set(CMAKE_CXX_STANDARD 20)
#[[add_executable(MatrixMulti MatrixMultiTest.cpp
        Complex.h
        MatrixMulti.h)]]

add_subdirectory(numerical_algorithm)
add_subdirectory(merkle_tree)
