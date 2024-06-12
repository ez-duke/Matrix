#include "s21_matrix_tests.h"

START_TEST(s21_eq_matrix_test0) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 1, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test1) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &B);
  s21_initialize_matrix(&A, 1, 2);
  s21_initialize_matrix(&B, 1, 2);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test2) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_initialize_matrix(&A, 1, 1e-8);
  s21_initialize_matrix(&B, 1.00000001, 1e-8);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test3) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_initialize_matrix(&A, 3, 2);
  s21_initialize_matrix(&B, 3, 2);
  B.matrix[0][2] = 0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test4) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(5, 4, &B);
  s21_initialize_matrix(&A, 1, 2);
  s21_initialize_matrix(&B, 1, 2);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test5) {
  matrix_t A = {};
  matrix_t B = {};

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_test6) {
  matrix_t A = {.rows = 1, .columns = 1};
  matrix_t B = {.rows = 1, .columns = 1};

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
}
END_TEST

Suite *s21_eq_matrix_test_suite() {
  Suite *s = suite_create("s21_eq_matrix");
  TCase *tc_case = tcase_create("s21_eq_matrix_case");

  tcase_add_test(tc_case, s21_eq_matrix_test0);
  tcase_add_test(tc_case, s21_eq_matrix_test1);
  tcase_add_test(tc_case, s21_eq_matrix_test2);
  tcase_add_test(tc_case, s21_eq_matrix_test3);
  tcase_add_test(tc_case, s21_eq_matrix_test4);
  tcase_add_test(tc_case, s21_eq_matrix_test5);
  tcase_add_test(tc_case, s21_eq_matrix_test6);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_eq_matrix_tests() {
  Suite *s = s21_eq_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
