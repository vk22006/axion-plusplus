#include <iostream>
#include <vector>
#include "axion/matrix.hpp"

axion::Matrix::Matrix(size_t rows, size_t cols) {
    this->rows = rows;
    this->cols = cols;
    M.resize(rows, std::vector<double>(cols));
}

axion::Matrix::Matrix(const std::vector<std::vector<double>>& M) {
    this->M = M;
    cols = M[0].size();
    rows = M.size();
}

std::vector<std::vector<double>> axion::Matrix::add(const std::vector<std::vector<double>>& mat_A, const std::vector<std::vector<double>>& mat_B) {
    std::vector<std::vector<double>> mat_C;
    mat_C.resize(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = mat_A[i][j] + mat_B[i][j];
        }
    }

    return mat_C;
}

std::vector<std::vector<double>> axion::Matrix::subtract(const std::vector<std::vector<double>>& mat_A, const std::vector<std::vector<double>>& mat_B) {
    std::vector<std::vector<double>> mat_C;
    mat_C.resize(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_C[i][j] = mat_A[i][j] - mat_B[i][j];
        }
    }

    return mat_C;
}

std::vector<std::vector<double>> axion::Matrix::transposeOf(const std::vector<std::vector<double>>& mat_A) {
    std::vector<std::vector<double>> mat_t;
    mat_t.resize(rows, std::vector<double>(cols));

    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            mat_t[i][j] = mat_A[j][i];
        }
    }

    return mat_t;
}

size_t axion::Matrix::rowCount() {
    return rows;
}

size_t axion::Matrix::colCount() {
    return cols;
}

void axion::Matrix::input(std::vector<std::vector<double>>& mat) {
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            std::cin >> mat[i][j];
        }
    }
}

void axion::Matrix::display(const std::vector<std::vector<double>>& mat) {
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}