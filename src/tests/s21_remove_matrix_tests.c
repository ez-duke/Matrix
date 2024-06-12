#include "s21_matrix_tests.h"

START_TEST(s21_remove_matrix_test0) {
  matrix_t A;

  s21_create_matrix(4, 2, &A);
  s21_remove_matrix(&A);

  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test1) {
  matrix_t A = {};

  s21_remove_matrix(&A);

  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test2) {
  matrix_t *A = NULL;

  s21_remove_matrix(A);

  ck_assert_ptr_null(A);
}
END_TEST

Suite *s21_remove_matrix_test_suite() {
  Suite *s = suite_create("s21_remove_matrix");
  TCase *tc_case = tcase_create("s21_remove_matrix_case");

  tcase_add_test(tc_case, s21_remove_matrix_test0);
  tcase_add_test(tc_case, s21_remove_matrix_test1);
  tcase_add_test(tc_case, s21_remove_matrix_test2);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_remove_matrix_tests() {
  Suite *s = s21_remove_matrix_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
