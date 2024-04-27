#include "s21_tests.h"

TEST(test_CalcComplements, test_calc_complements_1) {
  int a_rows = 3, a_cols = 3;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[3][3] = {{1., 2., 3.}, {0, 4., 2.}, {5, 2, 1}};

  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  int c_rows = 3, c_cols = 3;
  S21Matrix c_matrix(c_rows, c_cols);
  double c_value[3][3] = {{0., 10., -20.}, {4, -14., 8.}, {-8.0, -2, 4}};

  for (int i = 0; i < c_rows; i++)
    for (int j = 0; j < c_cols; j++) c_matrix(i, j) = c_value[i][j];

  S21Matrix complements(a_matrix.CalcComplements());
  ASSERT_TRUE(complements.EqMatrix(c_matrix));
}

TEST(test_CalcComplements, test_calc_complements_2) {
  int a_rows = 3, a_cols = 3;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[3][3] = {{2., 5., 7.}, {6, 3., 4}, {5, -2, -3}};

  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  int c_rows = 3, c_cols = 3;
  S21Matrix c_matrix(c_rows, c_cols);
  double c_value[3][3] = {{-1., 38., -27.}, {1, -41., 29.}, {-1.0, 34, -24}};

  for (int i = 0; i < c_rows; i++)
    for (int j = 0; j < c_cols; j++) c_matrix(i, j) = c_value[i][j];

  S21Matrix complements(a_matrix.CalcComplements());
  ASSERT_TRUE(complements.EqMatrix(c_matrix));
}

TEST(test_CalcComplements, throw_test_1) {
  int a_rows = 2, a_cols = 3;
  S21Matrix a_matrix(a_rows, a_cols);
  double a_value[2][3] = {
      {1., 2., 3.},
      {4., 5., 6.3},
  };
  for (int i = 0; i < a_rows; ++i)
    for (int j = 0; j < a_cols; ++j) a_matrix(i, j) = a_value[i][j];

  EXPECT_ANY_THROW(a_matrix.CalcComplements());
}

TEST(test_CalcComplements, throw_test_2) {
  S21Matrix a_matrix;
  EXPECT_ANY_THROW(a_matrix.CalcComplements());
}