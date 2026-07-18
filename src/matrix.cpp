#include <iostream>
#include <vector>
#include "axion/matrix.hpp"

axion::Matrix::Matrix(size_t rows, size_t cols) {
    this->rows = rows;
    this->cols = cols;
    M.resize(rows, std::vector<double>(cols));
}

axion::Matrix::Matrix(const matrix& M) {
    this->M = M;
    cols = M[0].size();
    rows = M.size();
}

// MATRIX OPERATIONS ===========================================

axion::Matrix axion::Matrix::operator+(Matrix& mat) {
    Matrix res_mat(rows, cols);

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            res_mat.M[i][j] = M[i][j] + mat.M[i][j];
        }
    }
    return res_mat;
}

axion::Matrix axion::Matrix::operator-(Matrix& mat) {
    Matrix res_mat(rows, cols);

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            res_mat.M[i][j] = M[i][j] - mat.M[i][j];
        }
    }
    return res_mat;
}

// SCALAR OPERATIONS ===========================================

axion::Matrix axion::Matrix::operator+(int x) {
    Matrix mat(rows, cols);

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat.M[i][j] = M[i][j] + x;
        }
    }
    return mat;
}

axion::Matrix axion::Matrix::operator-(int x) {
    Matrix mat(rows, cols);

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat.M[i][j] = M[i][j] - x;
        }
    }
    return mat;
}

axion::Matrix axion::Matrix::operator*(int x) {
    Matrix mat(rows, cols);

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat.M[i][j] = M[i][j] * x;
        }
    }
    return mat;
}

axion::Matrix axion::Matrix::operator/(int x) {
    Matrix mat(rows, cols);

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat.M[i][j] = M[i][j] / x;
        }
    }
    return mat;
}


axion::Matrix axion::Matrix::transpose() {
    matrix mat_t;
    mat_t.resize(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_t[i][j] = M[j][i];
        }
    }

    return mat_t;
}

double axion::Matrix::operator()(int i, int j) {
    return M[i][j];
}

size_t axion::Matrix::rows_() const {
    return rows;
}

size_t axion::Matrix::cols_() const {
    return cols;
}

std::istream& axion::operator>>(std::istream& in, Matrix& mat) {
    for(int i=0; i<mat.cols_(); i++) {
        for(int j=0; j<mat.rows_(); j++) {
            in >> mat.M[i][j];
        }
    }

    return in;
}

std::ostream& axion::operator<<(std::ostream &out, Matrix &mat)
{
    for(int i=0; i<mat.cols_(); i++) {
        for(int j=0; j<mat.rows_(); j++) {
            out << mat.M[i][j] << " ";
        }
        out << "\n";
    }

    return out;
}

