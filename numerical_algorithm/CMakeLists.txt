cmake_minimum_required(VERSION 3.28)
project(numerical_algorithm)

set(CMAKE_CXX_STANDARD 20)
#[[add_executable(complexTest ComplexTest.cpp
      Complex.h)]]
#[[add_executable(MatrixMulti MatrixMultiTest.cpp
        Complex.h
        MatrixMulti.h)]]
#[[
add_executable(MatrixMulti MatrixMultiTest.cpp
        Complex.h
        MatrixMulti.h)]]
#add_executable(fourier_series_test fourier_series_test.cpp)
add_executable(fast_fourier_trans_test
        fast_fourier_trans_test.cpp
        fast_fourier_trans.h)