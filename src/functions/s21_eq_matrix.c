#include "../s21_matrix.h"

int s21_eq_matrix(const matrix_t *A, const matrix_t *B) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !B || B->rows <= 0 ||
      B->columns <= 0 || A->columns != B->columns || A->rows != B->rows ||
      !A->matrix || !B->matrix)
    return FAILURE;

  int equal = 1;
  for (int i = 0; equal && i < A->rows; i++) {
    for (int j = 0; equal && j < A->columns; j++) {
      if (s21_fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) equal = 0;
    }
  }
  return equal;
}

double s21_fabs(double x) {
  if (x < 0) x = -x;
  return x;
}
