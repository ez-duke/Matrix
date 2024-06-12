#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !A->matrix) return 1;
  if (A->columns != A->rows) return 2;

  int error = 0;
  *result = 0;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    matrix_t temp = {};
    error = s21_create_matrix(A->rows, A->columns, &temp);

    if (!error) {
      s21_gauss_det(A, &temp, result);
      s21_remove_matrix(&temp);
    }
  }
  return error;
}

void s21_swap_zero_pivot(matrix_t *A, int i, int j) {
  double *temp = A->matrix[i];
  A->matrix[i] = A->matrix[j];
  A->matrix[j] = temp;
}

void s21_gauss_det(const matrix_t *A, matrix_t *temp, double *result) {
  s21_copy_matrix(*A, temp);
  int n = A->rows, sign = 0, error = 0;

  for (int i = 0; !error && i < n; i++) {
    int bup = i;
    while (i < n && s21_fabs(temp->matrix[i][bup]) < 1e-6) i++;
    if (i == n) {
      error = 1;
    } else if (bup != i) {
      s21_swap_zero_pivot(temp, bup, i);
      sign = !sign;
    }
    i = bup;

    for (int k = i + 1; !error && k < n; k++) {
      double ratio = temp->matrix[k][i] / temp->matrix[i][i];
      for (int j = 0; i < n - 1 && j < n; j++) {
        temp->matrix[k][j] -= temp->matrix[i][j] * ratio;
      }
    }
  }

  if (!error) {
    *result = 1;
    for (int i = 0; i < A->rows; i++) *result *= temp->matrix[i][i];
    if (sign && s21_fabs(*result) >= 1e-6) *result *= -1;
  }
}
