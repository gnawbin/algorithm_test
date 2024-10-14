cmake_minimum_required(VERSION 3.28)
project(numerical_algorithm)

set(CMAKE_CXX_STANDARD 20)
#add_executable(GauseJordanMatrixInvTest GauseJordanMatrixInvTest.cpp)
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
#[[
add_executable(fast_fourier_trans_test
        fast_fourier_trans_test.cpp
        fast_fourier_trans.h)]]
#add_executable(random_sample_analysis_test
 #      random_sample_analysis_test.cpp
     # random_sample_analysis.h)
#add_executable(RND_test
 #       RND_test.cpp
 #     RND.h)
add_executable(total_pivoting_gaussian_elimination_test
        total_pivoting_gaussian_elimination_test.cpp
        total_pivoting_gaussian_elimination.h)