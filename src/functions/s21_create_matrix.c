#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (!result) return 1;

  int error = 0;

  if (rows <= 0 || columns <= 0) {
    error = 1;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) error = 1;
  }

  for (int i = 0; !error && i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      error = 1;
      for (int j = 0; j < i; j++) {
        free(result->matrix[j]);
      }
      free(result->matrix);
    }
  }

  if (!error) {
    result->rows = rows;
    result->columns = columns;
  } else {
    result->rows = 0;
    result->columns = 0;
  }
  return error;
}

void s21_initialize_matrix(matrix_t *A, double start, double increment) {
  double num = start;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = num;
      num += increment;
    }
  }
}

void s21_copy_matrix(matrix_t A, matrix_t *B) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      B->matrix[i][j] = A.matrix[i][j];
    }
  }
}
