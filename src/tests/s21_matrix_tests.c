#include "s21_matrix_tests.h"

int main() {
  int result = 0;

  result += s21_create_matrix_tests();
  putchar('\n');
  result += s21_remove_matrix_tests();
  putchar('\n');
  result += s21_eq_matrix_tests();
  putchar('\n');
  result += s21_sum_matrix_tests();
  putchar('\n');
  result += s21_sub_matrix_tests();
  putchar('\n');
  result += s21_mult_number_tests();
  putchar('\n');
  result += s21_mult_matrix_tests();
  putchar('\n');
  result += s21_transpose_tests();
  putchar('\n');
  result += s21_calc_complements_tests();
  putchar('\n');
  result += s21_determinant_tests();
  putchar('\n');
  result += s21_inverse_matrix_tests();

  return (result == 0) ? 0 : 1;
}
