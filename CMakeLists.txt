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

add_executable(matrix_demo
    examples/matrix_demo.cpp
)
add_executable(transpose_matrix
    examples/transpose_matrix.cpp
)
add_executable(scalar_operations
    examples/scalar_operations.cpp
)

target_link_libraries(matrix_demo
    PRIVATE
        axion
)
target_link_libraries(transpose_matrix
    PRIVATE
        axion
)
target_link_libraries(scalar_operations
    PRIVATE
        axion
)