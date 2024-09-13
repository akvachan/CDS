#include <iostream>
#include <iterator>
#include <tuple>

#include "CDS_SimpleHashMap.hpp"

/*
int main() {
  CDS_Matrix<float> matrixA{0.1, 0.1, 0.1, 0.2, 0.2, 0.2, 0.3, 0.3, 0.3};
  CDS_Matrix<float> matrixB(3, 3);
  CDS_Matrix<float> vector(3, 1);

  CDS_Matrix<float> identityMatrix = CDS_Matrix<float>::Identity(5, 5);
  CDS_Matrix<float> nullMatrix = CDS_Matrix<float>::Null(5, 5);
  CDS_Matrix<float> rotationMatrix = CDS_Matrix<float>::Rotation(3);
  rotationMatrix.SetDegree(90);
  CDS_Matrix<float> rotatedVector = rotationMatrix * vector;

  CDS_Matrix<float> matrixC = matrixA * matrixB;
  CDS_Matrix<float> matrixD = matrixA + matrixB;
  CDS_Matrix<float> matrixF = matrixA - matrixB;
  CDS_Matrix<float> matrixScaled = 4 * matrixA;
  CDS_Matrix<float> translatedVector = matrixA * vector;

  matrixC.Reshape(1, 5);
  matrixC.SetColumn(1, std::vector<float>{0.1, 0.2, 0.3});
  matrixC.SetRow(1, std::vector<float>{0.1, 0.2, 0.3});
  CDS_Matrix<float> submatrix = matrixC.ExcludeColumns({2}).ExcludeRows({0, 2});
  std::vector<float> diagonal = matrixC.GetDiagonal();
  std::vector<float> column = matrixC.GetColumn(1);
  std::vector<float> row = matrixC.GetRow(1);
  std::tuple<int, int> shape = matrixC.GetShape();

  matrixA++;
  matrixA--;

  bool isSquare = matrixA.IsSquare();
  bool isNormal = matrixA.IsNormal();
  bool isSymmetric = matrixA.IsSymmetric();
  bool isUpperTriangular = matrixA.IsUpperTriangular();
  bool isLowerTriangular = matrixA.IsLowerTriangular();
  bool isAddable = matrixA.IsAddable(matrixD);
  bool isMultipliable = matrixA.IsMultipliable(matrixD);
  bool isDiagonal = matrixA.IsDiagonal();
  bool isDiagonalizable = matrixA.IsDiagonalizable();
  bool isInvertible = matrixA.IsInvertible();

  matrixA.Fill(1);
  matrixA.Transpose();
  matrixA.Inverse();
  matrixA.Diagonalize();
  matrixA.ConjugateTranspose();
  matrixA.Conjugate();

  float matrixDet = matrixA.Determinant();
  float matrixTrace = matrixA.Trace();
  int matrixRank = matrixA.Rank();
  int matrixNullity = matrixA.Nullity();

  std::pair<CDS_Matrix<float>, CDS_Matrix<float>> QRtuple =
      matrixA.Decompose(CDS_Matrix<float>::Order::QR);
  std::pair<CDS_Matrix<float>, CDS_Matrix<float>> RQtuple =
      matrixA.Decompose(CDS_Matrix<float>::Order::RQ);

  std::tuple<std::vector<float>> eigenVectors = matrixA.Eigenvecs();
  std::tuple<float> eigenValues = matrixA.Eigenvals();
}
*/

int main() {
  CDS_SimpleHashMap map;
  map.Print();
}
