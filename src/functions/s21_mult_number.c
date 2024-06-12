#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !A->matrix) return 1;

  int error = s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; !error && i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return error;
}
