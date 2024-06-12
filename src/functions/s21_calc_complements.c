#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !A->matrix) return 1;
  if (A->columns != A->rows) return 2;

  int error = s21_create_matrix(A->rows, A->columns, result);

  if (!error && A->rows == 1) {
    result->matrix[0][0] = 1;
  } else if (!error) {
    matrix_t temp = {};
    error = s21_create_matrix(A->rows - 1, A->columns - 1, &temp);

    for (int i = 0; !error && i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = s21_calc_minor(A, &temp, i, j);
      }
    }

    if (!error) s21_remove_matrix(&temp);
  }

  return error;
}

double s21_calc_minor(matrix_t *A, matrix_t *temp, int a, int b) {
  double det = 0;
  int count = 0, rank = A->rows - 1;

  for (int i = 0; i <= rank; i++) {
    for (int j = 0; j <= rank; j++) {
      if (i == a || j == b) continue;
      temp->matrix[count / rank][count % rank] = A->matrix[i][j];
      count++;
    }
  }

  s21_determinant(temp, &det);
  if ((a + b) % 2 && s21_fabs(det) >= 1e-6) det *= -1;
  return det;
}
