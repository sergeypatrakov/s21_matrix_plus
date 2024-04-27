#include "s21_tests.h"

TEST(test_Inverse, inverse_1) {
  int a_rows = 3, a_cols = 3;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[3][3] = {{2., 5., 7.}, {6, 3., 4.}, {5, -2, -3}};

  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  int c_rows = 3, c_cols = 3;
  S21Matrix c_matrix(c_rows, c_cols);
  double c_value[3][3] = {{1., -1., 1.}, {-38, 41., -34.}, {27, -29, 24}};

  for (int i = 0; i < c_rows; i++)
    for (int j = 0; j < c_cols; j++) c_matrix(i, j) = c_value[i][j];

  S21Matrix inverse(a_matrix.InverseMatrix());
  ASSERT_TRUE(inverse.EqMatrix(c_matrix));
}

TEST(Ttest_Inverse, inverse_2) {
  int a_rows = 4, a_cols = 4;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[4][4] = {
      {6., -5., 8., 4}, {9, 7., 5., 2}, {7, 5, 3, 7}, {-4, 8., -8., -3}};
  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  int c_rows = 4, c_cols = 4;
  S21Matrix c_matrix(c_rows, c_cols);
  double c_value[4][4] = {{5.56, -0.77, -0.93, 4.73},
                          {-3, 0.5, 0.5, -2.5},
                          {-5.36, 0.87, 0.83, -4.63},
                          {-1.12, 0.04, 0.36, -0.96}};

  for (int i = 0; i < c_rows; i++)
    for (int j = 0; j < c_cols; j++) c_matrix(i, j) = c_value[i][j];

  S21Matrix inverse(a_matrix.InverseMatrix());
  ASSERT_TRUE(inverse.EqMatrix(c_matrix));
}

TEST(test_Inverse, throw_test_1) {
  int a_rows = 3, a_cols = 3;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[3][3] = {
      {-1., 1., 3.},
      {-0.1, 0.1, 0.3},
      {4., -4., -12},
  };
  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  EXPECT_ANY_THROW(a_matrix.InverseMatrix());
}

TEST(test_Inverse, throw_test_2) {
  int a_rows = 2, a_cols = 3;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[3][3] = {
      {-1., 1., 3.},
      {-0.1, 0.1, 0.3},
  };
  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  EXPECT_ANY_THROW(a_matrix.InverseMatrix());
}

TEST(TestInverse, test_5) {
  S21Matrix a_matrix;
  EXPECT_ANY_THROW(a_matrix.InverseMatrix());
}