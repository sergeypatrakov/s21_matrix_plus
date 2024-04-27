#include "s21_tests.h"

TEST(test_Determinant, determinant_1) {
  int rowsA = 3, colsA = 3;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[3][3] = {{2, 6, 1}, {3, 1, 4}, {5, 4, 8}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int det = matrixA.Determinant();
  int result = -33;
  int assert = 0;
  if (det == result)
    assert = 1;
  else
    assert = 0;
  ASSERT_TRUE(assert);
}

TEST(test_Determinant, determinant_2) {
  int rowsA = 2, colsA = 2;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[2][2] = {{2, 6}, {4, 8}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int det = matrixA.Determinant();
  int result = -8;
  int assert = 0;
  if (det == result)
    assert = 1;
  else
    assert = 0;
  ASSERT_TRUE(assert);
}

TEST(test_Determinant, determinant_3) {
  int rowsA = 4, colsA = 4;
  S21Matrix matrixA(rowsA, colsA);
  double numberA[4][4] = {
      {2, 6, -4, 8}, {15, 0.3, 42, 0}, {1, 1, 1, 1}, {5, 4.32, 76, 2}};
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      matrixA(i, j) = numberA[i][j];
    }
  }
  int det = matrixA.Determinant();
  int result = -2012;
  int assert = 0;
  if (det == result)
    assert = 1;
  else
    assert = 0;
  ASSERT_TRUE(assert);
}

TEST(test_Determinant, test_3) {
  int a_rows = 2, a_cols = 3;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[2][3] = {
      {-1., 1., 3.},
      {-0.1, 0.1, 0.3},
  };
  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  EXPECT_ANY_THROW(a_matrix.Determinant());
}

TEST(test_Determinant, test_4) {
  S21Matrix a_matrix;
  EXPECT_ANY_THROW(a_matrix.Determinant());
}