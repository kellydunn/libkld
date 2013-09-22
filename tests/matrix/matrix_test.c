#include <stdlib.h>
#include <check.h>
#include "../../src/matrix/matrix.h"

START_TEST (test_new_matrix) {
  kld_matrix_t * m = (kld_matrix_t*) new_matrix();
  fail_if(m->rows != NULL, "Unexpected rows after initialization");
  fail_if(m->cols != NULL, "Unexpected cols after initialization");
} END_TEST;

Suite * new_matrix_suite() {
  Suite * s = suite_create("matrix");
  
  TCase * tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_new_matrix);

  suite_add_tcase(s, tc_core);
  
  return s;
}

int main() {
  int num_failed = 0;

  Suite * matrix_suite = new_matrix_suite();
  SRunner * matrix_suite_runner = srunner_create(matrix_suite);

  srunner_run_all(matrix_suite_runner, CK_NORMAL);
  num_failed = srunner_ntests_failed(matrix_suite_runner);

  srunner_free(matrix_suite_runner);

  return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
