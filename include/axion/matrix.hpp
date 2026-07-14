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
        matrix add(const matrix& mat_A, const matrix& mat_B);
        matrix subtract(const matrix& mat_A, const matrix& mat_B);
        matrix transposeOf(const matrix& mat_A);

        size_t rowCount();
        size_t colCount();

        void input(matrix& mat);
        void display(const matrix& mat);
};

} //namespace axion