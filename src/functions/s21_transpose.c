#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !A->matrix) return 1;

  int error = s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; !error && i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return error;
}
