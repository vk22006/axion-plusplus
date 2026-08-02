#pragma once

#include "config.hpp"
#include "version.hpp"
#include <iosfwd>

namespace axion {

/**
 * @brief Represents a two-dimensional matrix.
 *
 * The Matrix class provides basic linear algebra operations
 * including arithmetic, transposition, scalar operations,
 * and matrix multiplication.
 */

  class Matrix {
    private:
      matrix M;
      size_t rows;
      size_t cols;

    public:
      /**
       * @brief Constructs an empty matrix with zero dimensions.
       */
      Matrix();
      /**************************************************************
       * @brief Constructs a zero-initialized matrix.
       *
       * @param rows Number of rows.
       * @param cols Number of columns.
       **************************************************************/
      Matrix(size_t rows, size_t cols);
      /**************************************************************
       * @brief Constructs a matrix object from existing matrix type.
       *
       * @param M 2D array matrix (std::vector<std::vector<double>>)
       * @throws InvalidShapeError
       * if the matrix is empty or matrix should have same dimensions.
       **************************************************************/
      Matrix(const matrix &M);

      /**************************************************************
       * @brief Converts an matrix to identity matrix.
       * The matrix should be empty
       *
       * @param dimension Dimension of the square matrix
       * @throws InvalidShapeError
       * if given dimensions is a negative value
       **************************************************************/
      void identity(double dimension);
      /**************************************************************
       * @brief Fills the matrix with given value.
       * The matrix should be empty
       *
       * @param val Value to be filled in entire matrix
       **************************************************************/
      void fill(int val);


      //! Matrix Operations (Matrix with Matrix)
      /**************************************************************
       * @brief Adds two matrices.
       *
       * @param mat Matrix to add.
       * @return Sum of both matrices.
       *
       * @throws MatrixDimensionError
       * if dimensions differ.
       **************************************************************/
      Matrix operator+(const Matrix &mat) const;
      /**************************************************************
       * @brief Subtracts two matrices.
       *
       * @param mat Matrix to add.
       * @return Difference of both matrices.
       *
       * @throws MatrixDimensionError
       * if dimensions differ.
       **************************************************************/
      Matrix operator-(const Matrix &mat) const;
      /**************************************************************
       * @brief Multiplies two matrices.
       *
       * @param mat Matrix to add.
       * @return Product of both matrices.
       *
       * @throws MatrixDimensionError
       * if dimensions differ.
       **************************************************************/
      Matrix operator*(const Matrix &mat) const;

      //! Scalar Operations (Matrix with number)
      /**************************************************************
       * @brief Adds a value to an matrix.
       *
       * @param x Value to add.
       * @return Scalar sum of the matrix.
       **************************************************************/
      Matrix operator+(int x) const;
      /**************************************************************
       * @brief Subtracts a value to an matrix.
       *
       * @param x Value to subtract.
       * @return Scalar difference of the matrix.
       **************************************************************/
      Matrix operator-(int x) const;
      /**************************************************************
       * @brief Multiplies a value to an matrix.
       *
       * @param x Value to multiply.
       * @return Scalar product of the matrix.
       **************************************************************/
      Matrix operator*(int x) const;
      /**************************************************************
       * @brief Divides a value with an matrix.
       *
       * @param x Value to divide.
       * @return Scalar division of the matrix.
       * 
       * @throws DivisionByZeroError 
       * if x is 0
       **************************************************************/
      Matrix operator/(int x) const;

      /**************************************************************
       * @brief Transforms the matrix into its transpose form
       *
       * @return Transpose of the matrix.
       **************************************************************/
      Matrix transpose();

      /**************************************************************
       * @brief Returns element based on its index
       *
       * @param i Index at row
       * @param j Index at column
       * @return Element located in given index
       * 
       * @throws InvalidIndexError
       * if given index is invalid
       **************************************************************/
      double operator()(int i, int j);
      /**************************************************************
       * @brief Checks if two matrices are equal
       *
       * @param mat Matrix to be compared
       * @return If both matrices are equal or not
       * 
       * @throws InvalidIndexError
       * if given index is invalid
       **************************************************************/
      bool operator==(const Matrix &mat);
      /**************************************************************
       * @brief Compliment of operator==()
       *
       * @param mat Matrix to be compared
       * @return If both matrices are equal or not
       * 
       * @throws InvalidIndexError
       * if given index is invalid
       **************************************************************/
      bool operator!=(const Matrix &mat);

      /**************************************************************
       * @brief Returns the number of rows of the matrix
       *
       * @return Number of rows of the matrix
       **************************************************************/
      size_t rows_() const;
      /**************************************************************
       * @brief Returns the number of columns of the matrix
       *
       * @return Number of columns of the matrix
       **************************************************************/
      size_t cols_() const;

      /**************************************************************
       * @brief Collects matrix input from the user
       *
       * @param in Input stream
       * @param mat Matrix where input values to be stored
       **************************************************************/
      friend std::istream &operator>>(std::istream &in, Matrix &mat);
      /**************************************************************
       * @brief Displays the values of the matrix
       *
       * @param out Output stream
       * @param mat Matrix where values to be displayed
       **************************************************************/
      friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
    };
} // namespace axion