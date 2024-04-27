#include "s21_tests.h"

TEST(test_SumMatrix, default_sum_1) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  S21Matrix matrixB(rowsA, colsA);
  double numberB[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[3][3] = {{10, 10, 10}, {10, 10, 10}, {10, 10, 10}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA.SumMatrix(matrixB);
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SumMatrix, default_sum_2) {
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
  double numberResult[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA.SumMatrix(matrixB);
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SumMatrix, operator_sum_1) {
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
  double numberResult[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA += matrixB;
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SumMatrix, operator_sum_2) {
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
  double numberResult[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixA = matrixA + matrixB;
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_SumMatrix, throw_test) {
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
  EXPECT_ANY_THROW(matrixA.SumMatrix(matrixB));
}

TEST(test_SumMatrix, throw_operator_test) {
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
  EXPECT_ANY_THROW(matrixA + matrixB);
}