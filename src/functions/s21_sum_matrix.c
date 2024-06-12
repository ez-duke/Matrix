#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !B || B->rows <= 0 ||
      B->columns <= 0 || !A->matrix || !B->matrix)
    return 1;
  if (A->columns != B->columns || A->rows != B->rows) return 2;

  int error = s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; !error && i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return error;
}
