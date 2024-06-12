#include "s21_matrix_tests.h"

START_TEST(s21_sub_matrix_test0) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &validate);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&B, 1, 1);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &validate), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_sub_matrix_test1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  s21_create_matrix(4, 4, &validate);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &validate), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_sub_matrix_test2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(4, 5, &A);
  s21_create_matrix(5, 4, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_test3) {
  matrix_t A = {.rows = 1, .columns = 1};
  matrix_t B = {.rows = 1, .columns = 1};

  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), 1);
}
END_TEST

START_TEST(s21_sub_matrix_test4) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
}
END_TEST

START_TEST(s21_sub_matrix_test5) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &validate);

  A.matrix[0][0] = 4, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 1, A.matrix[1][1] = 4, A.matrix[1][2] = -2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 1, A.matrix[2][2] = 0;

  B.matrix[0][0] = 0, B.matrix[0][1] = 5, B.matrix[0][2] = 8;
  B.matrix[1][0] = -3, B.matrix[1][1] = 1, B.matrix[1][2] = 10;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);

  validate.matrix[0][0] = 4, validate.matrix[0][1] = -3,
  validate.matrix[0][2] = -5;
  validate.matrix[1][0] = 4, validate.matrix[1][1] = 3,
  validate.matrix[1][2] = -12;
  validate.matrix[2][0] = -1, validate.matrix[2][1] = -3,
  validate.matrix[2][2] = -1;

  ck_assert_int_eq(s21_eq_matrix(&result, &validate), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_sub_matrix_test6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t validate;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &validate);
  A.matrix[0][0] = -1;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result, &validate), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&validate);
}
END_TEST

START_TEST(s21_sub_matrix_test7) {
  matrix_t A = {.rows = -1, .columns = -1};
  matrix_t B = {.rows = -1, .columns = -1};
  matrix_t result;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), 1);
}
END_TEST

Suite *s21_sub_matrix_test_suite() {
  Suite *s = suite_create("s21_sub_matrix");
  TCase *tc_case = tcase_create("s21_sub_matrix_case");

  tcase_add_test(tc_case, s21_sub_matrix_test0);
  tcase_add_test(tc_case, s21_sub_matrix_test1);
  tcase_add_test(tc_case, s21_sub_matrix_test2);
  tcase_add_test(tc_case, s21_sub_matrix_test3);
  tcase_add_test(tc_case, s21_sub_matrix_test4);
  tcase_add_test(tc_case, s21_sub_matrix_test5);
  tcase_add_test(tc_case, s21_sub_matrix_test6);
  tcase_add_test(tc_case, s21_sub_matrix_test7);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_sub_matrix_tests() {
  Suite *s = s21_sub_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
