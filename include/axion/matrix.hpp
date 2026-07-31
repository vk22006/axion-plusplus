#pragma once

#include "config.hpp"
#include "version.hpp"
#include <iosfwd>

namespace axion {

class Matrix {
  private:
    matrix M;
    size_t rows;
    size_t cols;

  public:
    Matrix();
    Matrix(size_t rows, size_t cols);
    Matrix(const matrix &M);

    // Identity Matrix
    void identity(double dimension);
    void fill(int val);

    // Matrix Operations (Matrix with Matrix)
    Matrix operator+(const Matrix &mat) const;
    Matrix operator-(const Matrix &mat) const;
    Matrix operator*(const Matrix &mat) const;

    // Scalar Operations (Matrix with number)
    Matrix operator+(int x) const;
    Matrix operator-(int x) const;
    Matrix operator*(int x) const;
    Matrix operator/(int x) const;

    Matrix transpose();

    double operator()(int i, int j);    // Returns element based on its index
    bool operator==(const Matrix &mat); // Checks if two matrices are equal
    bool operator!=(const Matrix &mat);

    size_t rows_() const;
    size_t cols_() const;

    friend std::istream &operator>>(std::istream &in, Matrix &mat);
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
  };
} // namespace axion