#include "s21_matrix_tests.h"

START_TEST(s21_transpose_test0) {
  matrix_t A;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(3, 1, &A);
  s21_create_matrix(1, 3, &validate);

  ck_assert_int_eq(s21_transpose(&A, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, &result), FAILURE);
  ck_assert_int_eq(result.rows, validate.rows);
  ck_assert_int_eq(result.columns, validate.columns);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_transpose_test1) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(-2, 3, &A);

  ck_assert_int_eq(s21_transpose(&A, &result), 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_test2) {
  matrix_t A = {};
  matrix_t result;

  ck_assert_int_eq(s21_transpose(&A, &result), 1);
}
END_TEST

START_TEST(s21_transpose_test3) {
  matrix_t A = {.rows = 1, .columns = 1};
  matrix_t result = {};

  ck_assert_int_eq(s21_transpose(&A, &result), 1);
}
END_TEST

START_TEST(s21_transpose_test4) {
  matrix_t A;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &validate);

  A.matrix[0][0] = 4, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 1, A.matrix[1][1] = 4, A.matrix[1][2] = -2;

  ck_assert_int_eq(s21_transpose(&A, &result), 0);

  validate.matrix[0][0] = 4, validate.matrix[0][1] = 1,
  validate.matrix[1][0] = 2, validate.matrix[1][1] = 4,
  validate.matrix[2][0] = 3, validate.matrix[2][1] = -2;

  ck_assert_int_eq(s21_eq_matrix(&result, &validate), SUCCESS);
  ck_assert_int_eq(result.rows, validate.rows);
  ck_assert_int_eq(result.columns, validate.columns);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

Suite *s21_transpose_test_suite() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc_case = tcase_create("s21_transpose_case");

  tcase_add_test(tc_case, s21_transpose_test0);
  tcase_add_test(tc_case, s21_transpose_test1);
  tcase_add_test(tc_case, s21_transpose_test2);
  tcase_add_test(tc_case, s21_transpose_test3);
  tcase_add_test(tc_case, s21_transpose_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_transpose_tests() {
  Suite *s = s21_transpose_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
