#include "s21_tests.h"

TEST(test_MulMatrix, mul_normal_matrix_1) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{1, 1}, {1, 1}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 2, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][2] = {{1, 1}, {1, 1}};
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }

  matrixA.MulMatrix(matrixB);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{2, 2}, {2, 2}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulMatrix, mul_normal_matrix_2) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{3, 2}, {8, 1}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 2, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][2] = {{9, 0}, {2, 4}};
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  matrixA.MulMatrix(matrixB);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{31, 8}, {74, 4}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulMatrix, mul_normal_matrix_3) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{9.3, 2.3}, {134, 0.65}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 2, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][2] = {{4, 7.3}, {0.12, 56.4}};
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }

  matrixA.MulMatrix(matrixB);
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{37.476, 197.61}, {536.078, 1014.86}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulMatrix, throw_test) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{9.3, 2.3}, {134, 0.65}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 4, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][2] = {{4, 7.3}, {0.12, 56.4}};
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  EXPECT_ANY_THROW(matrixA.MulMatrix(matrixB));
}

TEST(test_MulMatrix, operator_mul_matrix_1) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{3, 2}, {8, 1}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 2, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][2] = {{9, 0}, {2, 4}};
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  matrixA *= matrixB;
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{31, 8}, {74, 4}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  ASSERT_TRUE(matrixA.EqMatrix(matrixResult));
}

TEST(test_MulMatrix, operator_mul_matrix_2) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{3, 2}, {8, 1}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 2, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][2] = {{9, 0}, {2, 4}};
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  S21Matrix matrixResult(rowsA, colsA);
  double numberResult[2][2] = {{31, 8}, {74, 4}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixResult(i, j) = numberResult[i][j];
    }
  }
  matrixResult = matrixA * matrixB;
  ASSERT_TRUE(matrixResult.EqMatrix(matrixResult));
}

TEST(test_MulMatrix, throw_operator_test) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{9.3, 2.3}, {134, 0.65}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int rowsB = 4, colsB = 2;
  S21Matrix matrixB(rowsB, colsB);
  double numberB[2][2] = {{4, 7.3}, {0.12, 56.4}};
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      matrixB(i, j) = numberB[i][j];
    }
  }
  EXPECT_ANY_THROW(matrixA * matrixB);
}