#include "s21_tests.h"

TEST(test_Transpose, default_transpose_1) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  S21Matrix matrixTranspose(matrixA.Transpose());
  ASSERT_TRUE(matrixTranspose.EqMatrix(matrixResult));
}

TEST(test_Transpose, default_transpose_2) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 1, 1}, {1, 1, 0}, {0, 0, 0}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{1, 1, 0}, {1, 1, 0}, {1, 0, 0}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  S21Matrix matrixTranspose(matrixA.Transpose());
  ASSERT_TRUE(matrixTranspose.EqMatrix(matrixResult));
}