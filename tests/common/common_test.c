#include <stdlib.h>
#include <check.h>
#include "../../src/common/common.h"

START_TEST (test_byte_cmp) {
  unsigned char * a = (unsigned char *) "test";
  unsigned char * a2 = (unsigned char *) "test";
  unsigned char * b = (unsigned char *) "test1";
  unsigned char * c = (unsigned char *) "case";

  fail_if(byte_cmp(a, b) >= 0, "a is intended to be less than b");
  fail_if(byte_cmp(a, a2) != 0, "a is intended to be equal to a2");
  fail_if(byte_cmp(a, c) <= 0, "a is intended to be greater than c");
} END_TEST

START_TEST (test_byte_array_len) {
  unsigned char * a = (unsigned char *) "test";
  unsigned char * b = (unsigned char *) "test1";
  unsigned char * c = (unsigned char *) "test12";

  fail_if(byte_array_len(a) != 4, "the length of a should be 4.");
  fail_if(byte_array_len(b) != 5, "the length of b should be 5.");
  fail_if(byte_array_len(c) != 6, "the length of c should be 6.");
} END_TEST

Suite * new_common_suite() {
  Suite * s = suite_create("common");

  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_byte_cmp);
  tcase_add_test(tc_core, test_byte_array_len);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int num_failed = 0;

  Suite * common_suite = new_common_suite();
  SRunner * common_suite_runner = srunner_create(common_suite);

  srunner_run_all(common_suite_runner, CK_NORMAL);
  num_failed = srunner_ntests_failed(common_suite_runner);

  srunner_free(common_suite_runner);

  return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
