#pragma once

/**
 * @file CDS_Matrix.hpp
 * @brief Header file for the CDS_Matrix class template.
 *
 * This file contains the definition and documentation of the CDS_Matrix class,
 * a template class used for matrix operations, including arithmetic, matrix
 * transformations, and other utility functions such as transpose, inverse, and
 * decomposition.
 */

#include <tuple>
#include <vector>

/**
 * @brief A matrix class template that supports matrix operations,
 * transformations, and decompositions.
 *
 * @tparam T Type of the elements in the matrix (e.g., float, double, int).
 */
template <typename T> class CDS_Matrix {
public:
  /**
   * @brief Enum for specifying the order of matrix decompositions.
   *
   * The Order enum is used to specify whether to perform QR or RQ decomposition
   * on a matrix.
   */
  enum class Order {
    QR, ///< QR decomposition
    RQ  ///< RQ decomposition
  };

  /**
   * @brief Constructs a matrix with a given list of elements.
   *
   * @param elements A list of elements to initialize the matrix.
   */
  CDS_Matrix(std::initializer_list<T> elements);

  /**
   * @brief Constructs a matrix with a given number of rows and columns.
   *
   * @param rows Number of rows.
   * @param cols Number of columns.
   */
  CDS_Matrix(int rows, int cols);

  /**
   * @brief Creates an identity matrix of size rows x cols.
   *
   * @param rows Number of rows.
   * @param cols Number of columns.
   * @return Identity matrix of size rows x cols.
   */
  static CDS_Matrix<T> Identity(int rows, int cols);

  /**
   * @brief Creates a null (zero) matrix of size rows x cols.
   *
   * @param rows Number of rows.
   * @param cols Number of columns.
   * @return Null matrix of size rows x cols.
   */
  static CDS_Matrix<T> Null(int rows, int cols);

  /**
   * @brief Creates a rotation matrix for a given dimension.
   *
   * @param dimension The dimension (e.g., 2D, 3D).
   * @return Rotation matrix.
   */
  static CDS_Matrix<T> Rotation(int dimension);

  /**
   * @brief Sets the degree of rotation for the matrix.
   *
   * @param degree Degree of rotation.
   */
  void SetDegree(float degree);

  /**
   * @brief Performs matrix multiplication with another matrix.
   *
   * @param other The other matrix to multiply with.
   * @return Resulting matrix after multiplication.
   */
  CDS_Matrix<T> operator*(const CDS_Matrix<T> &other) const;

  /**
   * @brief Performs matrix addition with another matrix.
   *
   * @param other The other matrix to add.
   * @return Resulting matrix after addition.
   */
  CDS_Matrix<T> operator+(const CDS_Matrix<T> &other) const;

  /**
   * @brief Performs matrix subtraction with another matrix.
   *
   * @param other The other matrix to subtract.
   * @return Resulting matrix after subtraction.
   */
  CDS_Matrix<T> operator-(const CDS_Matrix<T> &other) const;

  /**
   * @brief Scales the matrix by a scalar.
   *
   * @param scalar Scalar value to multiply the matrix by.
   * @return Resulting matrix after scaling.
   */
  friend CDS_Matrix<T> operator*(float scalar, const CDS_Matrix<T> &matrix);

  /**
   * @brief Multiplies the matrix with a vector.
   *
   * @param vector The vector to multiply with.
   * @return Resulting vector after multiplication.
   */
  std::vector<T> operator*(const std::vector<T> &vector) const;

  /**
   * @brief Reshapes the matrix to a new dimension.
   *
   * @param newRows New number of rows.
   * @param newCols New number of columns.
   */
  void Reshape(int newRows, int newCols);

  /**
   * @brief Sets a specific column with new values.
   *
   * @param colIndex Index of the column to set.
   * @param values New values for the column.
   */
  void SetColumn(int colIndex, const std::vector<T> &values);

  /**
   * @brief Sets a specific row with new values.
   *
   * @param rowIndex Index of the row to set.
   * @param values New values for the row.
   */
  void SetRow(int rowIndex, const std::vector<T> &values);

  /**
   * @brief Excludes specific columns from the matrix.
   *
   * @param colIndices Indices of the columns to exclude.
   * @return Resulting matrix after excluding columns.
   */
  CDS_Matrix<T> ExcludeColumns(std::initializer_list<int> colIndices);

  /**
   * @brief Excludes specific rows from the matrix.
   *
   * @param rowIndices Indices of the rows to exclude.
   * @return Resulting matrix after excluding rows.
   */
  CDS_Matrix<T> ExcludeRows(std::initializer_list<int> rowIndices);

  /**
   * @brief Gets the diagonal of the matrix.
   *
   * @return A vector containing the diagonal elements.
   */
  std::vector<T> GetDiagonal() const;

  /**
   * @brief Gets a specific column from the matrix.
   *
   * @param colIndex Index of the column to retrieve.
   * @return A vector containing the elements of the column.
   */
  std::vector<T> GetColumn(int colIndex) const;

  /**
   * @brief Gets a specific row from the matrix.
   *
   * @param rowIndex Index of the row to retrieve.
   * @return A vector containing the elements of the row.
   */
  std::vector<T> GetRow(int rowIndex) const;

  /**
   * @brief Gets the shape of the matrix (rows, cols).
   *
   * @return A tuple containing the number of rows and columns.
   */
  std::tuple<int, int> GetShape() const;

  /**
   * @brief Increments all matrix elements by 1 (postfix operator).
   */
  void operator++(int);

  /**
   * @brief Decrements all matrix elements by 1 (postfix operator).
   */
  void operator--(int);

  /**
   * @brief Fills the matrix with a specific value.
   *
   * @param value The value to fill the matrix with.
   */
  void Fill(T value);

  /**
   * @brief Computes the transpose of the matrix.
   */
  void Transpose();

  /**
   * @brief Computes the inverse of the matrix.
   */
  void Inverse();

  /**
   * @brief Diagonalizes the matrix.
   */
  void Diagonalize();

  /**
   * @brief Computes the conjugate transpose of the matrix.
   */
  void ConjugateTranspose();

  /**
   * @brief Computes the conjugate of the matrix.
   */
  void Conjugate();

  /**
   * @brief Computes the determinant of the matrix.
   *
   * @return The determinant of the matrix.
   */
  T Determinant() const;

  /**
   * @brief Computes the trace of the matrix.
   *
   * @return The trace of the matrix.
   */
  T Trace() const;

  /**
   * @brief Computes the rank of the matrix.
   *
   * @return The rank of the matrix.
   */
  int Rank() const;

  /**
   * @brief Computes the nullity of the matrix.
   *
   * @return The nullity of the matrix.
   */
  int Nullity() const;

  // Friend function for row access using subscript operator
  std::vector<T> &operator[](CDS_Matrix<T> &matrix, int rowIndex);

  // Friend function for element access using subscript operator
  T &operator[](CDS_Matrix<T> &matrix, std::pair<int, int> indices);

  // Declaration of is-Member functions

  /**
   * @brief Checks if the matrix is square (rows == cols).
   *
   * @return true if the matrix is square, false otherwise.
   */
  bool IsSquare() const;

  /**
   * @brief Checks if the matrix is normal (A * A^T == A^T * A).
   *
   * @return true if the matrix is normal, false otherwise.
   */
  bool IsNormal() const;

  /**
   * @brief Checks if the matrix is symmetric (A == A^T).
   *
   * @return true if the matrix is symmetric, false otherwise.
   */
  bool IsSymmetric() const;

  /**
   * @brief Checks if the matrix is invertible.
   *
   * @return true if the matrix is invertible, false otherwise.
   */
  bool IsInvertible() const;

  /**
   * @brief Checks if the matrix is diagonal.
   *
   * @return true if the matrix is diagonal, false otherwise.
   */
  bool IsDiagonal() const;

  /**
   * @brief Checks if the matrix is diagonalizable.
   *
   * @return true if the matrix is diagonalizable, false otherwise.
   */
  bool IsDiagonalizable() const;

  /**
   * @brief Checks if the matrix is upper triangular.
   *
   * @return true if the matrix is upper triangular, false otherwise.
   */
  bool IsUpperTriangular() const;

  /**
   * @brief Checks if the matrix is lower triangular.
   *
   * @return true if the matrix is lower triangular, false otherwise.
   */
  bool IsLowerTriangular() const;

  /**
   * @brief Checks if the current matrix is addable to another matrix.
   *
   * @param other The other matrix to compare dimensions.
   * @return true if matrices can be added, false otherwise.
   */
  bool IsAddable(const CDS_Matrix<T> &other) const;

  /**
   * @brief Checks if the current matrix can be multiplied by another matrix.
   *
   * @param other The other matrix to check multiplication compatibility.
   * @return true if matrices can be multiplied, false otherwise.
   */
  bool IsMultipliable(const CDS_Matrix<T> &other) const;

  /**
   * @brief Decomposes the matrix into a QR or RQ decomposition.
   *
   * @param order Decomposition order (QR or RQ).
   * @return A pair of matrices representing the decomposition.
   */
  std::pair<CDS_Matrix<T>, CDS_Matrix<T>> Decompose(Order order);

  /**
   * @brief Computes the eigenvectors of the matrix.
   *
   * @return A tuple containing the eigenvectors.
   */
  std::tuple<std::vector<T>> Eigenvecs() const;

  /**
   * @brief Computes the eigenvalues of the matrix.
   *
   * @return A tuple containing the eigenvalues.
   */
  std::tuple<T> Eigenvals() const;

private:
  std::vector<std::vector<T>>
      data;       ///< Matrix data stored as a vector of vectors
  int rows, cols; ///< Number of rows and columns in the matrix
};
