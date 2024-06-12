#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!A || A->rows <= 0 || A->columns <= 0 || !A->matrix) return 1;
  if (A->columns != A->rows) return 2;

  int error = 0;
  double det = 0;
  s21_determinant(A, &det);
  if (s21_fabs(det) < 1e-6) error = 2;

  if (!error) {
    matrix_t complements = {}, transpose = {};
    error = s21_calc_complements(A, &complements);
    if (!error) error = s21_transpose(&complements, &transpose);
    if (!error) {
      s21_remove_matrix(&complements);
      error = s21_mult_number(&transpose, 1.0 / det, result);
      if (!error) s21_remove_matrix(&transpose);
    }
  }

  return error;
}
