#include "s21_matrix_tests.h"

START_TEST(s21_determinant_test0) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(2, 3, &A);

  ck_assert_int_eq(s21_determinant(&A, &result), 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test1) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0, A.matrix[0][1] = 0, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;

  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_le(s21_fabs(result - 0.0), 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test2) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;

  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_le(s21_fabs(result + 40.0), 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test3) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 0, A.matrix[1][2] = 0;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;

  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_le(s21_fabs(result - 0.0), 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test4) {
  matrix_t A;
  double result = 0;

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 3, A.matrix[1][1] = 5, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = 1, A.matrix[2][2] = 2;

  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_le(s21_fabs(result + 32.0), 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test5) {
  matrix_t A = {.columns = 1};
  double result = 0;
  ck_assert_int_eq(s21_determinant(&A, &result), 1);
}
END_TEST

Suite *s21_determinant_test_suite() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc_case = tcase_create("s21_determinant_case");

  tcase_add_test(tc_case, s21_determinant_test0);
  tcase_add_test(tc_case, s21_determinant_test1);
  tcase_add_test(tc_case, s21_determinant_test2);
  tcase_add_test(tc_case, s21_determinant_test3);
  tcase_add_test(tc_case, s21_determinant_test4);
  tcase_add_test(tc_case, s21_determinant_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_determinant_tests() {
  Suite *s = s21_determinant_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
