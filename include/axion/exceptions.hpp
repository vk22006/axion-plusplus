#pragma once

#include <stdexcept>
#include <string>
#include <sstream>

namespace axion {

/**
 * @brief Base exception class for all axion errors.
 *
 * All custom exceptions in the axion library derive from this class,
 * which itself extends @c std::runtime_error. Catch this type to
 * handle any axion-specific error in a single handler.
 */
class AxionError : public std::runtime_error {
public:
    /**************************************************************
     * @brief Constructs an AxionError with a custom message.
     *
     * @param message Human-readable description of the error.
     **************************************************************/
    explicit AxionError(const std::string& message)
        : std::runtime_error(message) {}
};


/**
 * @brief Exception thrown when two matrices have incompatible dimensions
 *        for a given operation.
 *
 * Raised by arithmetic operations (e.g., addition, multiplication)
 * when the shapes of the operands do not satisfy the operation's
 * dimensional requirements.
 */
class MatrixDimensionError : public AxionError {
public:
    /**************************************************************
     * @brief Constructs a MatrixDimensionError with dimension details.
     *
     * Automatically formats an error message describing the
     * incompatible shapes of the two matrices involved.
     *
     * @param rows_a Number of rows in the first matrix.
     * @param cols_a Number of columns in the first matrix.
     * @param rows_b Number of rows in the second matrix.
     * @param cols_b Number of columns in the second matrix.
     * @param operation Optional name of the operation that failed
     *                  (e.g., @c "addition", @c "multiplication").
     **************************************************************/
    MatrixDimensionError(size_t rows_a, size_t cols_a,
                         size_t rows_b, size_t cols_b,
                         const std::string& operation = "")
        : AxionError(build_message(rows_a, cols_a, rows_b, cols_b, operation)) {}

    /**************************************************************
     * @brief Constructs a MatrixDimensionError with a custom message.
     *
     * @param message Human-readable description of the dimension error.
     **************************************************************/
    explicit MatrixDimensionError(const std::string& message)
        : AxionError(message) {}

private:
    /**************************************************************
     * @brief Builds the formatted error message string.
     *
     * @param rows_a Number of rows in the first matrix.
     * @param cols_a Number of columns in the first matrix.
     * @param rows_b Number of rows in the second matrix.
     * @param cols_b Number of columns in the second matrix.
     * @param operation Name of the failing operation (may be empty).
     * @return Formatted error message string.
     **************************************************************/
    static std::string build_message(size_t rows_a, size_t cols_a,
                                     size_t rows_b, size_t cols_b,
                                     const std::string& operation) {
        std::ostringstream oss;
        oss << "MatrixDimensionError";
        if (!operation.empty()) oss << " [" << operation << "]";
        oss << ": incompatible dimensions ("
            << rows_a << "x" << cols_a << ") and ("
            << rows_b << "x" << cols_b << ").";
        return oss.str();
    }
};

/**
 * @brief Exception thrown when a matrix element is accessed with an
 *        out-of-bounds index.
 *
 * Raised by element-access operations (e.g., @c operator()) when the
 * supplied row or column index exceeds the matrix dimensions.
 */
class InvalidIndexError : public AxionError {
public:
    /**************************************************************
     * @brief Constructs an InvalidIndexError with index details.
     *
     * Automatically formats an error message describing the
     * invalid index and the actual matrix bounds.
     *
     * @param row     Requested row index.
     * @param col     Requested column index.
     * @param max_rows Total number of rows in the matrix.
     * @param max_cols Total number of columns in the matrix.
     **************************************************************/
    InvalidIndexError(size_t row, size_t col,
                      size_t max_rows, size_t max_cols)
        : AxionError(build_message(row, col, max_rows, max_cols)) {}

    /**************************************************************
     * @brief Constructs an InvalidIndexError with a custom message.
     *
     * @param message Human-readable description of the index error.
     **************************************************************/
    explicit InvalidIndexError(const std::string& message)
        : AxionError(message) {}

private:
    /**************************************************************
     * @brief Builds the formatted error message string.
     *
     * @param row      Requested row index.
     * @param col      Requested column index.
     * @param max_rows Total number of rows in the matrix.
     * @param max_cols Total number of columns in the matrix.
     * @return Formatted error message string.
     **************************************************************/
    static std::string build_message(size_t row, size_t col,
                                     size_t max_rows, size_t max_cols) {
        std::ostringstream oss;
        oss << "InvalidIndexError: index (" << row << ", " << col << ") is out of bounds "
            << "for matrix of size (" << max_rows << "x" << max_cols << ").";
        return oss.str();
    }
};

/**
 * @brief Exception thrown when a matrix is constructed or used with an
 *        invalid shape.
 *
 * Raised when attempting to create a matrix with illegal dimensions,
 * such as a negative size, an empty matrix, or rows of unequal length.
 */
class InvalidShapeError : public AxionError {
public:
    /**************************************************************
     * @brief Constructs an InvalidShapeError with shape details.
     *
     * Automatically formats an error message describing the
     * invalid dimensions and an optional reason.
     *
     * @param rows   Number of rows in the invalid matrix.
     * @param cols   Number of columns in the invalid matrix.
     * @param reason Optional explanation of why the shape is invalid
     *               (e.g., @c "rows must be positive").
     **************************************************************/
    InvalidShapeError(size_t rows, size_t cols,
                      const std::string& reason = "")
        : AxionError(build_message(rows, cols, reason)) {}

    /**************************************************************
     * @brief Constructs an InvalidShapeError with a custom message.
     *
     * @param message Human-readable description of the shape error.
     **************************************************************/
    explicit InvalidShapeError(const std::string& message)
        : AxionError(message) {}

private:
    /**************************************************************
     * @brief Builds the formatted error message string.
     *
     * @param rows   Number of rows in the invalid matrix.
     * @param cols   Number of columns in the invalid matrix.
     * @param reason Explanation of the invalidity (may be empty).
     * @return Formatted error message string.
     **************************************************************/
    static std::string build_message(size_t rows, size_t cols,
                                     const std::string& reason) {
        std::ostringstream oss;
        oss << "InvalidShapeError: invalid matrix shape (" << rows << "x" << cols << ")";
        if (!reason.empty()) oss << " - " << reason;
        oss << ".";
        return oss.str();
    }
};

/**
 * @brief Exception thrown when a division by zero is attempted.
 *
 * Raised by scalar division operators (e.g., @c operator/) when the
 * divisor is zero, which would produce an undefined result.
 */
class DivisionByZeroError : public AxionError {
public:
    /**************************************************************
     * @brief Constructs a DivisionByZeroError with a default message.
     **************************************************************/
    DivisionByZeroError()
        : AxionError("DivisionByZeroError: division by zero is undefined.") {}

    /**************************************************************
     * @brief Constructs a DivisionByZeroError with a custom message.
     *
     * @param message Human-readable description of the error.
     **************************************************************/
    explicit DivisionByZeroError(const std::string& message)
        : AxionError(message) {}
};

} // namespace axion
