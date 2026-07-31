#pragma once

#include <stdexcept>
#include <string>
#include <sstream>

namespace axion {

// Base exception for all axion errors

class AxionError : public std::runtime_error {
public:
    explicit AxionError(const std::string& message)
        : std::runtime_error(message) {}
};


// Matrix errors
class MatrixDimensionError : public AxionError {
public:
    MatrixDimensionError(size_t rows_a, size_t cols_a,
                         size_t rows_b, size_t cols_b,
                         const std::string& operation = "")
        : AxionError(build_message(rows_a, cols_a, rows_b, cols_b, operation)) {}

    explicit MatrixDimensionError(const std::string& message)
        : AxionError(message) {}

private:
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

class InvalidIndexError : public AxionError {
public:
    InvalidIndexError(size_t row, size_t col,
                      size_t max_rows, size_t max_cols)
        : AxionError(build_message(row, col, max_rows, max_cols)) {}

    explicit InvalidIndexError(const std::string& message)
        : AxionError(message) {}

private:
    static std::string build_message(size_t row, size_t col,
                                     size_t max_rows, size_t max_cols) {
        std::ostringstream oss;
        oss << "InvalidIndexError: index (" << row << ", " << col << ") is out of bounds "
            << "for matrix of size (" << max_rows << "x" << max_cols << ").";
        return oss.str();
    }
};

class InvalidShapeError : public AxionError {
public:
    InvalidShapeError(size_t rows, size_t cols,
                      const std::string& reason = "")
        : AxionError(build_message(rows, cols, reason)) {}

    explicit InvalidShapeError(const std::string& message)
        : AxionError(message) {}

private:
    static std::string build_message(size_t rows, size_t cols,
                                     const std::string& reason) {
        std::ostringstream oss;
        oss << "InvalidShapeError: invalid matrix shape (" << rows << "x" << cols << ")";
        if (!reason.empty()) oss << " - " << reason;
        oss << ".";
        return oss.str();
    }
};

class DivisionByZeroError : public AxionError {
public:
    DivisionByZeroError()
        : AxionError("DivisionByZeroError: division by zero is undefined.") {}

    explicit DivisionByZeroError(const std::string& message)
        : AxionError(message) {}
};

} // namespace axion
