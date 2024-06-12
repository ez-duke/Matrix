#include "s21_matrix_tests.h"

START_TEST(s21_create_matrix_test0) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(3, 3, &A), 0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test1) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(0, 3, &A), 1);
}
END_TEST

START_TEST(s21_create_matrix_test2) {
  ck_assert_int_eq(s21_create_matrix(3, 3, NULL), 1);
}
END_TEST

START_TEST(s21_create_matrix_test3) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(8, -2, &A), 1);
}
END_TEST

START_TEST(s21_create_matrix_test4) {
  matrix_t A;

  ck_assert_int_eq(s21_create_matrix(3, 5, &A), 0);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_create_matrix_test_suite() {
  Suite *s = suite_create("s21_create_matrix");
  TCase *tc_case = tcase_create("s21_create_matrix_case");

  tcase_add_test(tc_case, s21_create_matrix_test0);
  tcase_add_test(tc_case, s21_create_matrix_test1);
  tcase_add_test(tc_case, s21_create_matrix_test2);
  tcase_add_test(tc_case, s21_create_matrix_test3);
  tcase_add_test(tc_case, s21_create_matrix_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_create_matrix_tests() {
  Suite *s = s21_create_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
