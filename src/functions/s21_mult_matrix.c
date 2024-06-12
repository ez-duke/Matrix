#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !B || B->rows <= 0 ||
      B->columns <= 0 || !A->matrix || !B->matrix)
    return 1;
  if (A->columns != B->rows) return 2;

  int error = s21_create_matrix(A->rows, B->columns, result);

  double sum;
  for (int i = 0; !error && i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      sum = 0.0;
      for (int k = 0; k < A->columns; k++) {
        sum += A->matrix[i][k] * B->matrix[k][j];
      }
      result->matrix[i][j] = sum;
    }
  }

  return error;
}
