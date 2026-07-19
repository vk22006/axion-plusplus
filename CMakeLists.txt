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
