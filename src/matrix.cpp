
#include "axion/matrix.hpp"
#include "axion/exceptions.hpp"
#include <iostream>
#include <vector>

axion::Matrix::Matrix() {
  rows = 0;
  cols = 0;
  M = {};
} // Creating an empty matrix

axion::Matrix::Matrix(size_t rows, size_t cols) {
  this->rows = rows;
  this->cols = cols;
  M.resize(rows, std::vector<double>(cols));
}

axion::Matrix::Matrix(const matrix &M) {
  rows = M.size();
  if (rows == 0)
    throw InvalidShapeError(0, 0, "matrix must have at least one row");

  cols = M[0].size();
  if (cols == 0)
    throw InvalidShapeError(rows, 0, "matrix must have at least one column");

  for (size_t i = 1; i < rows; i++) {
    if (M[i].size() != cols)
      throw InvalidShapeError(rows, cols,
                              "all rows must have the same number of columns");
  }

  this->M = M;
}

void axion::Matrix::identity(double dimension) {
  if (dimension <= 0)
    throw InvalidShapeError(static_cast<size_t>(dimension),
                            static_cast<size_t>(dimension),
                            "identity matrix dimension must be positive");

  rows = cols = static_cast<size_t>(dimension);
  M.assign(rows, std::vector<double>(cols, 0.0));
  for (size_t i = 0; i < rows; i++)
    M[i][i] = 1.0;
}

void axion::Matrix::fill(int val) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      M[i][j] = val;
    }
  }
}

// MATRIX OPERATIONS ===========================================

axion::Matrix axion::Matrix::operator+(const Matrix &mat) const {
  if (rows != mat.rows || cols != mat.cols)
    throw MatrixDimensionError(rows, cols, mat.rows, mat.cols, "addition");

  Matrix res_mat(rows, cols);
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      res_mat.M[i][j] = M[i][j] + mat.M[i][j];
  return res_mat;
}

axion::Matrix axion::Matrix::operator-(const Matrix &mat) const {
  if (rows != mat.rows || cols != mat.cols)
    throw MatrixDimensionError(rows, cols, mat.rows, mat.cols, "subtraction");

  Matrix res_mat(rows, cols);
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      res_mat.M[i][j] = M[i][j] - mat.M[i][j];
  return res_mat;
}

axion::Matrix axion::Matrix::operator*(const Matrix &mat) const {
  // Matrix multiplication requires: cols of A == rows of B
  if (cols != mat.rows)
    throw MatrixDimensionError(rows, cols, mat.rows, mat.cols,
                               "multiplication");

  Matrix res_mat(rows, mat.cols);
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < mat.cols; j++)
      for (size_t k = 0; k < cols; k++)
        res_mat.M[i][j] += M[i][k] * mat.M[k][j];
  return res_mat;
}

// SCALAR OPERATIONS ===========================================

axion::Matrix axion::Matrix::operator+(int x) const {
  Matrix mat(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mat.M[i][j] = M[i][j] + x;
    }
  }
  return mat;
}

axion::Matrix axion::Matrix::operator-(int x) const {
  Matrix mat(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mat.M[i][j] = M[i][j] - x;
    }
  }
  return mat;
}

axion::Matrix axion::Matrix::operator*(int x) const {
  Matrix mat(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mat.M[i][j] = M[i][j] * x;
    }
  }
  return mat;
}

axion::Matrix axion::Matrix::operator/(int x) const {
  if (x == 0)
    throw DivisionByZeroError();

  Matrix mat(rows, cols);
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      mat.M[i][j] = M[i][j] / x;
  return mat;
}

axion::Matrix axion::Matrix::transpose() {
  // Result is cols x rows
  matrix mat_t(cols, std::vector<double>(rows));

  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      mat_t[j][i] = M[i][j];

  return mat_t;
}

double axion::Matrix::operator()(int i, int j) {
  if (i < 0 || static_cast<size_t>(i) >= rows || j < 0 ||
      static_cast<size_t>(j) >= cols)
    throw InvalidIndexError(static_cast<size_t>(i), static_cast<size_t>(j),
                            rows, cols);
  return M[i][j];
}

bool axion::Matrix::operator==(const Matrix &mat) {
  if (rows != mat.rows || cols != mat.cols)
    throw MatrixDimensionError(rows, cols, mat.rows, mat.cols, "comparison");

  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      if (M[i][j] != mat.M[i][j])
        return false;
  return true;
}

bool axion::Matrix::operator!=(const Matrix &mat) { return !(*this == mat); }

size_t axion::Matrix::rows_() const { return rows; }

size_t axion::Matrix::cols_() const { return cols; }

std::istream &axion::operator>>(std::istream &in, Matrix &mat) {
  for (int i = 0; i < mat.rows_(); i++) {
    for (int j = 0; j < mat.cols_(); j++) {
      in >> mat.M[i][j];
    }
  }

  return in;
}

std::ostream &axion::operator<<(std::ostream &out, const Matrix &mat) {
  for (int i = 0; i < mat.rows_(); i++) {
    for (int j = 0; j < mat.cols_(); j++) {
      out << mat.M[i][j] << " ";
    }
    out << "\n";
  }

  return out;
}
