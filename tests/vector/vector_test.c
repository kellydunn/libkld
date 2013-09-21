#include <stdlib.h>
#include <stdio.h>
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

//Ensure the ability for a vector to correctly declare itself as empty
// ✔ A vector should be empty upon initialization
START_TEST (test_vector_is_empty) {
  kld_vector_t * v = (kld_vector_t *) new_vector();
  fail_if(vector_is_empty(v) != true, "Expected vector to be identified as empty upon initialization");

  // Testing after being inserted
  vector_insert(v, (void *) "test");
  fail_if(vector_is_empty(v) == true, "Expected vector to not be empty after inserting one element.");

  // TODO Test after being deleted
} END_TEST

//Ensure the ability to add once to a vector
// ✔ A vector should have the correct size after adding one
// ✔ A vector should have the correct capacity after adding one
// ✔ A vector should have the correct data after adding one
START_TEST (test_vector_insert_one) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_insert(v, (void*) "test");

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting one element.");
  fail_if(v->size != 1, "Unexpected size of vector after inserting one element.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Vector capacity should not change after inserting one element.");
  fail_if(v->data == NULL, "Vector should have data elements after inserting one element.");
  fail_if((strcmp((char*) vector_get(v, (v->size-1)), "test") != 0), "Unexpected data at expected location after inserting one.");
} END_TEST

//Ensure the ability to add once to a vector
// ✔ A vector should have the correct size after adding two
// ✔ A vector should have the correct capacity after adding two
// ✔ A vector should have the correct data after adding two
START_TEST (test_vector_insert_two) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_insert(v, (void*) "test-0");
  vector_insert(v, (void*) "test-1");

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting one element.");
  fail_if(v->size != 2, "Unexpected size of vector after inserting one element.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Vector capacity should not change after inserting one element.");
  fail_if(v->data == NULL, "Vector should have data elements after inserting one element.");
  fail_if((strcmp((char*) vector_get(v, 0), "test-0") != 0), "Unexpected data at expected location after inserting one.");
  fail_if((strcmp((char*) vector_get(v, 1), "test-1") != 0), "Unexpected data at expected location after inserting one.");
} END_TEST

//Ensure the ability to add once to a vector
// ✔ A vector should have the correct size after adding one
// ✔ A vector should have the correct capacity after adding one
// ✔ A vector should have the correct data after adding one
START_TEST (test_vector_insert_past_capacity) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  int i;
  for(i = 0; i < DEFAULT_VECTOR_CAPACITY + 1; i++) {
    char * insert_str = calloc(256, sizeof(char));
    sprintf(insert_str, "test-%d", i);
    vector_insert(v, (void*) insert_str); 
  }

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting past capacity.");
  fail_if(v->size != DEFAULT_VECTOR_CAPACITY + 1, "Unexpected size of vector after inserting past capacity.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY * 2, "Vector capacity should double after inserting past capacity.");
  fail_if(v->data == NULL, "Vector should have data elements after inserting one element.");

  for(i = 0; i < v->size; i++) {
    char test_str[16];
    sprintf(test_str, "test-%d", i);
    fail_if((strcmp((char*) vector_get(v, i), test_str) != 0), "Unexpected data at expected location after inserting past capacity.");
  }

} END_TEST

Suite * new_vector_suite() {
  Suite * s = suite_create("vector");
  
  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_new_vector);

  tcase_add_test(tc_core, test_vector_is_empty);

  tcase_add_test(tc_core, test_vector_insert_one);
  tcase_add_test(tc_core, test_vector_insert_two);
  tcase_add_test(tc_core, test_vector_insert_past_capacity);

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
