#pragma once

#include <axion/config.hpp>
#include <axion/version.hpp>

namespace axion {

class Matrix {
    private:
        matrix M;
        size_t rows;
        size_t cols;
    public:
        Matrix(size_t rows, size_t cols);
        Matrix(const matrix& M);

        matrix operator+(Matrix& mat_B);
        matrix operator-(Matrix& mat_B);

        matrix transpose();

        double operator()(int i, int j);   // Returns element based on its index

        size_t rows_() const;
        size_t cols_() const;

        void input(matrix& mat);
        friend std::ostream& operator<<(std::ostream& out, Matrix& mat);
};

// FIXME: Make the function to print matrix directly
std::ostream& operator<<(std::ostream& out, matrix& mat);

} //namespace axion