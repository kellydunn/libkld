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
  vector_append(v, (void *) "test");
  fail_if(vector_is_empty(v) == true, "Expected vector to not be empty after inserting one element.");

  // TODO Test after being deleted
} END_TEST

//Ensure the ability to add once to a vector
// ✔ A vector should have the correct size after adding one
// ✔ A vector should have the correct capacity after adding one
// ✔ A vector should have the correct data after adding one
START_TEST (test_vector_append_one) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_append(v, (void*) "test");

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
START_TEST (test_vector_append_two) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_append(v, (void*) "test-0");
  vector_append(v, (void*) "test-1");

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting one element.");
  fail_if(v->size != 2, "Unexpected size of vector after inserting one element.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Vector capacity should not change after inserting one element.");
  fail_if(v->data == NULL, "Vector should have data elements after inserting one element.");
  fail_if((strcmp((char*) vector_get(v, 0), "test-0") != 0), "Unexpected data at expected location after inserting two.");
  fail_if((strcmp((char*) vector_get(v, 1), "test-1") != 0), "Unexpected data at expected location after inserting two.");
} END_TEST

//Ensure the ability to add once to a vector
// ✔ A vector should have the correct size after adding one
// ✔ A vector should have the correct capacity after adding one
// ✔ A vector should have the correct data after adding one
START_TEST (test_vector_append_past_capacity) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  int i;
  for(i = 0; i < DEFAULT_VECTOR_CAPACITY + 1; i++) {
    char * insert_str = calloc(256, sizeof(char));
    sprintf(insert_str, "test-%d", i);
    vector_append(v, (void*) insert_str); 
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

//Ensure the ability to insert once into a vector
// ✔ A vector should have the correct size after inserting into a specific index
// ✔ A vector should have the correct data in the expected index after inserting once
START_TEST (test_vector_insert_at_0_once) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_insert_at(v, 0, (void*) "test");

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting one element.");
  fail_if(v->size != 1, "Unexpected size of vector after inserting one element.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Vector capacity should not change after inserting one element.");
  fail_if(v->data == NULL, "Vector should have data elements after inserting one element.");
  fail_if((strcmp((char*) vector_get(v, (v->size-1)), "test") != 0), "Unexpected data at expected location after inserting one.");
} END_TEST

//Ensure the ability to insert twice into a vector
// ✔ A vector should have the correct size after inserting into a specific index
// ✔ A vector should have the correct data in the expected indicies after inserting twice
START_TEST (test_vector_insert_at_0_twice) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_insert_at(v, 0, (void*) "test-1");
  vector_insert_at(v, 0, (void*) "test-0");

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting one element.");
  fail_if(v->size != 2, "Unexpected size of vector after inserting one element.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Vector capacity should not change after inserting one element.");
  fail_if(v->data == NULL, "Vector should have data elements after inserting one element.");
  fail_if((strcmp((char*) vector_get(v, 0), "test-0") != 0), "Unexpected data at expected location after inserting two.");
  fail_if((strcmp((char*) vector_get(v, 1), "test-1") != 0), "Unexpected data at expected location after inserting two.");
} END_TEST

//Ensure the ability to insert twice into a vector
// ✔ A vector should have the correct size after inserting into a specific index
// ✔ A vector should have the correct data in the expected indicies after inserting three times
START_TEST (test_vector_insert_at_0_twice_insert_at_1_once) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_insert_at(v, 0, (void*) "test-2");
  vector_insert_at(v, 0, (void*) "test-0");
  vector_insert_at(v, 1, (void*) "test-1");

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting one element.");
  fail_if(v->size != 3, "Unexpected size of vector after inserting one element.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Vector capacity should not change after inserting one element.");
  fail_if(v->data == NULL, "Vector should have data elements after inserting one element.");
  fail_if((strcmp((char*) vector_get(v, 0), "test-0") != 0), "Unexpected data at expected location after inserting three times.");
  fail_if((strcmp((char*) vector_get(v, 1), "test-1") != 0), "Unexpected data at expected location after inserting three times.");
  fail_if((strcmp((char*) vector_get(v, 2), "test-2") != 0), "Unexpected data at expected location after inserting three times.");
} END_TEST

//Ensure the ability to add once then remove once 
// ✔ A vector should correctly identify itself as empty after inserting once and removing once.
START_TEST (test_vector_append_one_and_remove_at_one) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_append(v, "test");
  vector_remove_at(v, 0);

  fail_if(vector_is_empty(v) != true, "Vector should be empty after inserting and deleting one.");

} END_TEST

//Ensure the ability to add twice then remove once 
// ✔ A vector should correctly identify itself as not empty after inserting twice and removing once.
// ✔ A vector should correctly return the correct value after removing at a specific index
START_TEST (test_vector_append_two_and_remove_at_one) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_append(v, "test-0");
  vector_append(v, "test-1");
  vector_remove_at(v, 0);

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting and deleting one.");
  fail_if(strcmp(vector_get(v, 0), "test-1") != 0, "Unexpected value at the first index after adding twice and removing once.");

} END_TEST

//Ensure the ability to add to capacity and remove once 
// ✔ A vector should correctly identify itself as not empty after inserting twice and removing once.
// ✔ A vector should correctly return the correct value after removing at a specific index
START_TEST (test_vector_append_to_capacity_and_remove_at_one) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  int i;
  for(i = 0; i < DEFAULT_VECTOR_CAPACITY; i++) {
    char * insert_str = calloc(256, sizeof(char));
    sprintf(insert_str, "test-%d", i);
    vector_append(v, (void*) insert_str); 
  }

  vector_remove_at(v, 0);

  fail_if(vector_is_empty(v) == true, "Vector should not be empty after inserting to capacity and deleting one.");
  fail_if(strcmp(vector_get(v, 0), "test-1") != 0, "Unexpected value at the first index after adding to capacity and removing once.");
  fail_if(v->capacity != DEFAULT_VECTOR_CAPACITY, "Expected capacity to decrease after removing below threshold.");
} END_TEST

START_TEST (test_vector_quicksort_empty) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  vector_quicksort(v);

  fail_if(vector_is_empty(v) != true, "Expected vector to be empty after quicksorting it immediately after initialization");
} END_TEST

START_TEST (test_vector_quicksort_1) {
  kld_vector_t * v = (kld_vector_t *) new_vector();
  int data = 1;
  vector_append(v, &data);

  vector_quicksort(v);

  fail_if((int *) vector_get(v, 0) != &data, "Expected first index of vector to be equal to the only element appeneded to it after quicksorting it");
  fail_if(v->size != 1, "Expected vector to retain size after quicksorting");
} END_TEST

START_TEST (test_vector_quicksort_10) {
  kld_vector_t * v = (kld_vector_t *) new_vector();
  int i;

  for(i = 10; i >0; i--) {
    int * data = calloc(1, sizeof(int));
    *data = i;
    vector_append(v, data);
  }

  vector_quicksort(v);

  for(i = 1; i < 11; i++) {
    int data  = *((int *) vector_get(v, i-1));
    fail_if(data != i, "Expected sorted values after calling quicksort on an array with 10 elements");
  }

  fail_if(!vector_is_sorted(v), "Expected vector to be sorted after quicksorting it");
} END_TEST

START_TEST (test_vector_is_sorted) {
  kld_vector_t * v = (kld_vector_t *) new_vector();
  int i;

  fail_if(!vector_is_sorted(v), "Expected vector to be sorted after initialization.");

  for(i = 10; i >0; i--) {
    int * data = calloc(1, sizeof(int));
    *data = i;
    vector_append(v, data);
  }

  fail_if(vector_is_sorted(v), "Expected vector to not be sorted when items added out of order.");

  vector_quicksort(v);

  fail_if(!vector_is_sorted(v), "Expected vector to be sorted when items added out of order then sorted.");

} END_TEST

Suite * new_vector_suite() {
  Suite * s = suite_create("vector");
  
  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_new_vector);

  tcase_add_test(tc_core, test_vector_is_empty);

  tcase_add_test(tc_core, test_vector_append_one);
  tcase_add_test(tc_core, test_vector_append_two);
  tcase_add_test(tc_core, test_vector_append_past_capacity);

  tcase_add_test(tc_core, test_vector_insert_at_0_once);
  tcase_add_test(tc_core, test_vector_insert_at_0_twice);
  tcase_add_test(tc_core, test_vector_insert_at_0_twice_insert_at_1_once);

  tcase_add_test(tc_core, test_vector_append_one_and_remove_at_one);
  tcase_add_test(tc_core, test_vector_append_two_and_remove_at_one);
  tcase_add_test(tc_core, test_vector_append_to_capacity_and_remove_at_one);

  tcase_add_test(tc_core, test_vector_quicksort_empty);
  tcase_add_test(tc_core, test_vector_quicksort_1);
  tcase_add_test(tc_core, test_vector_quicksort_10);

  tcase_add_test(tc_core, test_vector_is_sorted);
  
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
