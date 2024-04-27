#include "s21_tests.h"

TEST(test_MulNumber, mul_on_one) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = 1;
  matrixA.MulNumber(valueA);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulNumber, mul_on_negative_one) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = -1;
  matrixA.MulNumber(valueA);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulNumber, mul_on_zero) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = 0;
  matrixA.MulNumber(valueA);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulNumber, mul_on_two) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = 2;
  matrixA.MulNumber(valueA);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulNumber, mul_on_two_dot_five) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{2, 3}, {5, 6}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = 2.5;
  matrixA.MulNumber(valueA);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{5, 7.5}, {12.5, 15}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulNumber, mul_on_pi) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{2, 3}, {5, 6}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = 3.14;
  matrixA.MulNumber(valueA);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{6.28, 9.42}, {15.7, 18.84}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulNumber, wtf_mul_on_wtf) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{-29, 201}, {-381, 214}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = 3.12;
  matrixA.MulNumber(valueA);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{-90.48, 627.12}, {-1188.72, 667.68}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulNumber, mul_operator) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  double valueA = 2;
  matrixA *= valueA;
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}