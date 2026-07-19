#include <iostream>
#include <vector>
#include "axion/matrix.hpp"

axion::Matrix::Matrix() {
    rows = 0;
    cols = 0;
    M = {};
}  // Creating an empty matrix

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

void axion::Matrix::identity(double dimension) {
    rows = cols = dimension;
    M.resize(dimension, std::vector<double>(dimension));
    for(int i=0; i<dimension; i++) {
        for(int j=0; j<dimension; j++) {
            if(i==j) {
                M[i][j] = 1.0;
            }
        }
    }
}

void axion::Matrix::fill(int val) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            M[i][j] = val;
        }
    }
}

// MATRIX OPERATIONS ===========================================

axion::Matrix axion::Matrix::operator+(const Matrix& mat) const {
    Matrix res_mat(rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            res_mat.M[i][j] = M[i][j] + mat.M[i][j];
        }
    }
    return res_mat;
}

axion::Matrix axion::Matrix::operator-(const Matrix& mat) const {
    Matrix res_mat(rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            res_mat.M[i][j] = M[i][j] - mat.M[i][j];
        }
    }
    return res_mat;
}

axion::Matrix axion::Matrix::operator*(const Matrix& mat) const {
    Matrix res_mat(rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            res_mat.M[i][j] = 0;
            for(int k=0; k<rows; k++) {
                res_mat.M[i][j] += M[i][k] * mat.M[k][j];
            }
        }
    }

    return res_mat;
}

// SCALAR OPERATIONS ===========================================

axion::Matrix axion::Matrix::operator+(int x) const {
    Matrix mat(rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            mat.M[i][j] = M[i][j] + x;
        }
    }
    return mat;
}

axion::Matrix axion::Matrix::operator-(int x) const {
    Matrix mat(rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            mat.M[i][j] = M[i][j] - x;
        }
    }
    return mat;
}

axion::Matrix axion::Matrix::operator*(int x) const {
    Matrix mat(rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            mat.M[i][j] = M[i][j] * x;
        }
    }
    return mat;
}

axion::Matrix axion::Matrix::operator/(int x) const {
    Matrix mat(rows, cols);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            mat.M[i][j] = M[i][j] / x;
        }
    }
    return mat;
}


axion::Matrix axion::Matrix::transpose() {
    matrix mat_t;
    mat_t.resize(rows, std::vector<double>(cols));

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            mat_t[i][j] = M[j][i];
        }
    }

    return mat_t;
}

double axion::Matrix::operator()(int i, int j) {
    return M[i][j];
}

bool axion::Matrix::operator==(const Matrix& mat) {
    bool isEqual = false;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(M[i][j] == mat.M[i][j]) {
                isEqual = true;
            }
        }
    }

    return isEqual;
}

size_t axion::Matrix::rows_() const {
    return rows;
}

size_t axion::Matrix::cols_() const {
    return cols;
}

std::istream& axion::operator>>(std::istream& in, Matrix& mat) {
    for(int i=0; i<mat.rows_(); i++) {
        for(int j=0; j<mat.cols_(); j++) {
            in >> mat.M[i][j];
        }
    }

    return in;
}

std::ostream& axion::operator<<(std::ostream &out, const Matrix &mat)
{
    for(int i=0; i<mat.rows_(); i++) {
        for(int j=0; j<mat.cols_(); j++) {
            out << mat.M[i][j] << " ";
        }
        out << "\n";
    }

    return out;
}

