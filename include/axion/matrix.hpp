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

        // Matrix Operations (Matrix with Matrix)
        Matrix operator+(Matrix& mat);
        Matrix operator-(Matrix& mat);
        Matrix operator*(Matrix& mat);

        // Scalar Operations (Matrix with number)
        Matrix operator+(int x);
        Matrix operator-(int x);
        Matrix operator*(int x);
        Matrix operator/(int x);

        Matrix transpose();

        double operator()(int i, int j);   // Returns element based on its index

        size_t rows_() const;
        size_t cols_() const;

        friend std::istream& operator>>(std::istream& in, Matrix& mat);
        friend std::ostream& operator<<(std::ostream& out, Matrix& mat);
};

} //namespace axion