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

axion::matrix axion::Matrix::operator+(Matrix& mat_b) {
    matrix mat_C;
    mat_C.resize(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = M[i][j] + mat_b(i,j);
        }
    }
    return mat_C;
}

axion::matrix axion::Matrix::operator-(Matrix& mat_b) {
    matrix mat_C;
    mat_C.resize(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = M[i][j] - mat_b(i,j);
        }
    }
    return mat_C;
}

axion::matrix axion::Matrix::operator+(int x) {
    matrix mat_C(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = M[i][j] + x;
        }
    }
    return mat_C;
}

axion::matrix axion::Matrix::operator-(int x) {
    matrix mat_C(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = M[i][j] - x;
        }
    }
    return mat_C;
}

axion::matrix axion::Matrix::operator*(int x) {
    matrix mat_C(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = M[i][j] * x;
        }
    }
    return mat_C;
}

axion::matrix axion::Matrix::operator/(int x) {
    matrix mat_C(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = M[i][j] / x;
        }
    }
    return mat_C;
}


axion::matrix axion::Matrix::transpose() {
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

void axion::Matrix::input(matrix& mat) {
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            std::cin >> mat[i][j];
        }
    }
}

std::ostream& axion::operator<<(std::ostream &out, Matrix &mat)
{
    for(int i=0; i<mat.cols_(); i++) {
        for(int j=0; j<mat.rows_(); j++) {
            out << mat(i,j) << " ";
        }
        out << "\n";
    }

    return out;
}

std::ostream& axion::operator<<(std::ostream &out, matrix &mat) {
    int rows = mat[0].size();
    int cols = mat.size();
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            out << mat[i][j] << " ";
        }
        out << "\n";
    }

    return out;
}
