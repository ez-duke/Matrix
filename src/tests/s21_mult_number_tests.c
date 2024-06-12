#include "s21_matrix_tests.h"

START_TEST(s21_mult_number_test0) {
  matrix_t A;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &validate);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&validate, 3, 3);

  ck_assert_int_eq(s21_mult_number(&A, 3, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &validate), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_mult_number_test1) {
  matrix_t A;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &validate);

  ck_assert_int_eq(s21_mult_number(&A, 10, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &validate), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_mult_number_test2) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(-1, 5, &A);

  ck_assert_int_eq(s21_mult_number(&A, 5, &result), 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_test3) {
  matrix_t A = {.rows = 1, .columns = 1};

  ck_assert_int_eq(s21_mult_number(&A, -2, NULL), 1);
}
END_TEST

START_TEST(s21_mult_number_test4) {
  matrix_t A = {};
  matrix_t result = {};

  ck_assert_int_eq(s21_mult_number(&A, 0, &result), 1);
}
END_TEST

START_TEST(s21_mult_number_test5) {
  matrix_t A;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &validate);

  A.matrix[0][0] = 4, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 1, A.matrix[1][1] = 4, A.matrix[1][2] = -2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 1, A.matrix[2][2] = 0;

  ck_assert_int_eq(s21_mult_number(&A, -1, &result), 0);

  validate.matrix[0][0] = -4, validate.matrix[0][1] = -2,
  validate.matrix[0][2] = -3;
  validate.matrix[1][0] = -1, validate.matrix[1][1] = -4,
  validate.matrix[1][2] = 2;
  validate.matrix[2][0] = -2, validate.matrix[2][1] = -1,
  validate.matrix[2][2] = 0;

  ck_assert_int_eq(s21_eq_matrix(&result, &validate), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_mult_number_test6) {
  matrix_t A;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &validate);
  A.matrix[0][0] = -1;

  ck_assert_int_eq(s21_mult_number(&A, 1, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &validate), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

Suite *s21_mult_number_test_suite() {
  Suite *s = suite_create("s21_mult_number");
  TCase *tc_case = tcase_create("s21_mult_number_case");

  tcase_add_test(tc_case, s21_mult_number_test0);
  tcase_add_test(tc_case, s21_mult_number_test1);
  tcase_add_test(tc_case, s21_mult_number_test2);
  tcase_add_test(tc_case, s21_mult_number_test3);
  tcase_add_test(tc_case, s21_mult_number_test4);
  tcase_add_test(tc_case, s21_mult_number_test5);
  tcase_add_test(tc_case, s21_mult_number_test6);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_mult_number_tests() {
  Suite *s = s21_mult_number_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
