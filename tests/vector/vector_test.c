#include <stdlib.h>
#include <check.h>
#include "../../src/vector/vector.h"

//Ensure a new vector can be made
// ✔ Size should be 0
// ✔ Capacity should be ??
// ✔ Data should be NULL
START_TEST (test_new_vector) {
  kld_vector_t * v = (kld_vector_t *) new_vector();
  fail_if(v->size != 0, "Unexepected size for new vector");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Unexpected capacity for new vector");
  fail_if(v->data != NULL, "Unexpected data value for new vector");
} END_TEST

Suite * new_vector_suite() {
  Suite * s = suite_create("vector");
  
  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_new_vector);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int num_failed = 0;

  Suite * vector_suite = new_vector_suite();
  SRunner * vector_suite_runner = srunner_create(vector_suite);

  srunner_run_all(vector_suite_runner, CK_NORMAL);
  num_failed = srunner_ntests_failed(vector_suite_runner);

  srunner_free(vector_suite_runner);
  
  return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
