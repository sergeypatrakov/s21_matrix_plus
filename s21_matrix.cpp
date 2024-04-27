#include "./s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr){};

void S21Matrix::create_matrix() {
  if (rows_ < 0 || cols_ < 0)
    throw std::invalid_argument("Rows or Columns equal or less zero!");
  else {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_];
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  create_matrix();
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = 1;
}

S21Matrix::S21Matrix(const S21Matrix& other) noexcept
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  std::swap(matrix_, other.matrix_);
}

S21Matrix::~S21Matrix() noexcept {
  for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
  delete[] matrix_;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j)
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) return false;
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Uncorrect matrix");
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Uncorrect matrix");
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = matrix_[i][j] * num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) throw std::invalid_argument("cols != rows");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  std::swap(matrix_, result.matrix_);
  int temp = cols_;
  cols_ = result.cols_;
  result.cols_ = temp;
  temp = rows_;
  rows_ = result.rows_;
  result.rows_ = temp;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) result.matrix_[j][i] = matrix_[i][j];
  return result;
}

S21Matrix S21Matrix::Minor(int rows, int cols) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0, mi = 0; i < rows_; ++i) {
    if (i == rows) continue;
    for (int j = 0, mj = 0; j < cols_; ++j) {
      if (j == cols) continue;
      minor.matrix_[mi][mj] = matrix_[i][j];
      mj++;
    }
    mi++;
  }
  return minor;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) throw std::invalid_argument("Uncorrect matrix");
  if (rows_ == 0 || cols_ == 0)
    throw std::invalid_argument("Rows or cols is zero");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix minor(this->Minor(i, j));
      double det = minor.Determinant();
      int sign = ((i + j) % 2 != 0) ? -1 : 1;
      result.matrix_[i][j] = det * sign;
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) throw std::invalid_argument("Uncorrect matrix");
  if (rows_ == 0 || cols_ == 0)
    throw std::invalid_argument("Rows or cols is zero");
  if (rows_ == 1) return matrix_[0][0];
  double det = 0.0;
  for (int i = 0; i < cols_; ++i) {
    S21Matrix minor(Minor(0, i));
    det += matrix_[0][i] * (i % 2 == 0 ? 1 : -1) * minor.Determinant();
  }
  return det;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) throw std::invalid_argument("Uncorrect matrix");
  if (rows_ == 0 || cols_ == 0)
    throw std::invalid_argument("Rows or cols is zero");
  double det = this->Determinant();
  if (fabs(det) < 1e-10) throw std::invalid_argument("det is zero!");
  S21Matrix res(this->CalcComplements());
  res.MulNumber(1.0 / det);
  return res.Transpose();
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0)
    throw std::invalid_argument("Rows or Columns equal or less zero!");
  else if (i > rows_ || j > cols_)
    throw std::invalid_argument("Out of range");
  return matrix_[i][j];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == &other) return *this;
  S21Matrix result(other);
  std::swap(matrix_, result.matrix_);
  int temp = rows_;
  rows_ = result.rows_;
  result.rows_ = temp;
  temp = cols_;
  cols_ = result.cols_;
  result.cols_ = temp;
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  (*this).SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  (*this).SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Uncorrect matrix");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j)
      result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Uncorrect matrix");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j)
      result.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Uncorrect matrix");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j)
      result.matrix_[i][j] = matrix_[i][j] * other.matrix_[i][j];
  return result;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  (*this).MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  (*this).MulNumber(num);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }