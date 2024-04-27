#include "s21_tests.h"

TEST(test_SubMatrix, default_sub_1) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixB(rowsA, colsA);
  double numberB[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 19}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, -10}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA.SubMatrix(matrixB);
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SubMatrix, default_sub_2) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixB(rowsA, colsA);
  double numberB[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA.SubMatrix(matrixB);
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SubMatrix, operator_sub_1) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixB(rowsA, colsA);
  double numberB[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA -= matrixB;
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SubMatrix, operator_sub_2) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixB(rowsA, colsA);
  double numberB[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA = matrixA - matrixB;
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SubMatrix, throw_test) {
  int rowsA = 2, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][3] = {{1, 2, 3}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 2, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][3] = {
      {1, 2}, {7, 8}};  // преднамеренная ошибка, чтобы выкинуть throw
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  EXPECT_ANY_THROW(matrixA.SubMatrix(matrixB));
}

TEST(test_SubMatrix, throw_operator_test) {
  int rowsA = 2, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][3] = {{1, 2, 3}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 2, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][3] = {
      {1, 2}, {7, 8}};  // преднамеренная ошибка, чтобы выкинуть throw
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  EXPECT_ANY_THROW(matrixA - matrixB);
}