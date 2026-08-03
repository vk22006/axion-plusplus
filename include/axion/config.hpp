#pragma once

#include <vector>

/**
 * @file config.hpp
 * @brief Core type aliases used throughout the axion library.
 *
 * Centralizes fundamental type definitions so that the underlying
 * numeric representation can be changed in a single place without
 * modifying any other source files.
 */

namespace axion {
    //! Alias for the scalar element type used in all matrix operations.
    using Scalar = double;

    //! Alias for the index type used to address matrix rows and columns.
    using Index = size_t;

    //! Alias for the underlying 2-D container type (row-major).
    using matrix = std::vector<std::vector<double>>;
}