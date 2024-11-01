cmake_minimum_required(VERSION 3.28)
project(numerical_algorithm)

set(CMAKE_CXX_STANDARD 20)
add_executable(GauseJordanMatrixInvTest GauseJordanMatrixInvTest.cpp)
add_executable(complexTest ComplexTest.cpp
      Complex.h)
add_executable(MatrixMulti MatrixMultiTest.cpp
        Complex.h
        MatrixMulti.h)


add_executable(fourier_series_test fourier_series_test.cpp

)
add_executable( fast_walsh_series_test
        fast_walsh_series_test.cpp
)
add_executable( 5_3_smoothing_formula_test
        5_3_smoothing_formula_test.cpp
)
add_executable( evaluation_of_determinants_test
        evaluation_of_determinants_test.cpp
)
add_executable( rank_of_matrix_test
        rank_of_matrix_test.cpp
)
add_executable(cholesky_decompositionmethod_test
        cholesky_decompositionmethod_test.cpp
)

add_executable(fast_fourier_trans_test
        fast_fourier_trans_test.cpp
        fast_fourier_trans.h)
add_executable(random_sample_analysis_test
    random_sample_analysis_test.cpp
     random_sample_analysis.h)
add_executable(RND_test
       RND_test.cpp
    RND.h)
add_executable(total_pivoting_gaussian_elimination_test
        total_pivoting_gaussian_elimination_test.cpp
        total_pivoting_gaussian_elimination.h)
add_executable(trench_toeplitz_inv_test trench_toeplitz_inv_test.cpp)
add_executable(gauss-Jordan-elimination-test Gauss-jordan-Elimination-test.cpp Gauss-Jordan-Elimination.h)
add_executable(symmetric_positive_definite_test symmetric_positive_definite_test.cpp symmetric_positive_definite.h)
add_executable(triangular_decomposition_of_matrices_test
        triangular_decomposition_of_matrices_test.cpp
)
add_executable(household_transformation_qr_decomposition_test
        household_transformation_qr_decomposition_test.cpp
)
add_executable(kalman_filtering_test
        kalman_filtering_test.cpp
)
add_executable(  A_B_G_filtering_test
        A_B_G_filtering_test.cpp
)
add_executable(gamma_test
        gamma_test.cpp
)
add_executable(ingamma_test
        ingamma_test.cpp
)
add_executable(generalized_inverse_matrix_of_singular_matrix_test generalized_inverse_matrix_of_singular_matrix_test.cpp)
add_executable(singular_value_decomposition_test singular_value_decomposition_test.cpp)
add_executable(Poly_test Poly_test.cpp)
add_executable(symmetric_matrices_householder_transformation_test symmetric_matrices_householder_transformation_test.cpp)