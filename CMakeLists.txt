cmake_minimum_required(VERSION 3.20)

project(
    Axion
    VERSION 0.1.0
    DESCRIPTION "Lightweight Neural Network Library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =====================================================
# Library
# =====================================================

add_library(axion
    src/matrix.cpp
)

target_include_directories(axion
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# =====================================================
# Example Executable
# =====================================================

set(EXAMPLES
    matrix_demo
    transpose_matrix
    scalar_operations
    matrix_multiplication
)

foreach(example ${EXAMPLES})
    add_executable(${example}
        examples/${example}.cpp
    )

    target_link_libraries(${example}
        PRIVATE
            axion
    )
endforeach()

# =====================================================
# Tests
# =====================================================

enable_testing()

set(TESTS
    MatrixConstruction
    Identity
    Fill
    MatrixAddition
    MatrixSubtraction
    MatrixMultiplication
    ScalarOperations
    Transpose
    Equality
)

foreach(test ${TESTS})
    add_executable(${test}
        tests/${test}.cpp
    )

    target_include_directories(${test}
        PRIVATE
            ${PROJECT_SOURCE_DIR}/tests
    )

    target_link_libraries(${test}
        PRIVATE
            axion
    )

    add_test(NAME ${test} COMMAND ${test})
endforeach()

# =====================================================
# Benchmarks
# =====================================================

set(BENCHMARKS
    bench_matrix_addition
    bench_matrix_multiplication
    bench_matrix_transpose
)

foreach(bench ${BENCHMARKS})
    add_executable(${bench}
        benchmarks/matrix/${bench}.cpp
    )

    target_link_libraries(${bench}
        PRIVATE
            axion
    )
endforeach()

# =====================================================
# Documentation (Doxygen)
# =====================================================

find_package(Doxygen)

if(DOXYGEN_FOUND)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating Axion++ Documentation"
    )

endif()

