#include "s21_tests.h"

TEST(test_EqMatrix, equal_default_matrix_1) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  int result = 0;
  result = (matrixA.EqMatrix(matrixResult) == true) ? 1 : 0;
  ASSERT_TRUE(result);
}

TEST(test_EqMatrix, equal_default_matrix_2) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{1, 2}, {5, 6}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{1, 2}, {5, 6}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  int result = 0;
  result = (matrixA.EqMatrix(matrixResult) == true) ? 1 : 0;
  ASSERT_TRUE(result);
}