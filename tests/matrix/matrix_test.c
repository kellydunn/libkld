#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "../../src/matrix/matrix.h"

START_TEST (test_new_matrix) {
  kld_matrix_t * m = (kld_matrix_t*) new_matrix();
  fail_if(m->rows != NULL, "Unexpected rows after initialization");
  fail_if(m->cols != NULL, "Unexpected cols after initialization");
  fail_if(m->rows_capacity != DEFAULT_MATRIX_ROWS_CAPACITY, "Unexpected x bounds after initialization");
  fail_if(m->cols_capacity != DEFAULT_MATRIX_COLS_CAPACITY, "Unexpected y bounds after initialization");
  fail_if(m->rows_bounds != 0, "Unexpected x bounds after initialization");
  fail_if(m->cols_bounds != 0, "Unexpected y bounds after initialization");
} END_TEST

START_TEST(test_matrix_is_empty) {
  kld_matrix_t * m = (kld_matrix_t *) new_matrix();
  fail_if(!matrix_is_empty(m), "Matrix should be empty after initialization.");
} END_TEST

START_TEST(test_matrix_append_row) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  int i; 
  for(i = 0; i < 10; i++) {
    char *buf = calloc(256, sizeof(char));
    sprintf(buf, "test-%d", i);
    vector_append(v, buf);
  }

  kld_matrix_t * m = (kld_matrix_t *) new_matrix();
  matrix_append_row(m, v);
  
  fail_if(m->rows_bounds != 1, "Rows bounds were not updated after appending row.");
  fail_if(m->rows_capacity != DEFAULT_MATRIX_ROWS_CAPACITY, "Unexpected rows capacity after appending a row.");

  for(i = 0; i < 10; i++) {
    char *buf = calloc(256, sizeof(char));
    sprintf(buf, "test-%d", i);
    fail_if(strcmp(vector_get(m->rows[0], i), buf) != 0, "Unexpected row data after appending a row");
    fail_if(strcmp(vector_get(m->cols[i], 0), buf) != 0, "Unexpected col data after appending a row");
  }
  
} END_TEST

START_TEST(test_matrix_get_row) {
  kld_matrix_t * m = (kld_matrix_t *) new_matrix();

  int i, j; 
  for(i = 0; i < 10; i++) {
    kld_vector_t * v = (kld_vector_t *) new_vector();

    for(j = 0; j < 10; j++) {
      char *buf = calloc(256, sizeof(char));
      sprintf(buf, "test-%d-%d", i, j);
      vector_append(v, buf);
    }

    matrix_append_row(m, v);
  }
 
  kld_vector_t * row = (kld_vector_t *) matrix_get_row(m, 0);
 
  for(i = 0; i < 10; i++) {
    char *buf = calloc(256, sizeof(char));
    sprintf(buf, "test-%d-%d", 0, i);
    fail_if(strcmp(vector_get(row, i), buf) != 0, "Unexpected row data after appending a row");
  }
  
} END_TEST

START_TEST(test_matrix_get_col) {
  kld_matrix_t * m = (kld_matrix_t *) new_matrix();

  int i, j; 
  for(i = 0; i < 10; i++) {
    kld_vector_t * v = (kld_vector_t *) new_vector();

    for(j = 0; j < 10; j++) {
      char *buf = calloc(256, sizeof(char));
      sprintf(buf, "test-%d-%d", i, j);
      vector_append(v, buf);
    }

    matrix_append_row(m, v);
  }
 
  kld_vector_t * col = (kld_vector_t *) matrix_get_col(m, 0);
 
  for(i = 0; i < 10; i++) {
    char *buf = calloc(256, sizeof(char));
    sprintf(buf, "test-%d-%d", i, 0);
    fail_if(strcmp(vector_get(col, i), buf) != 0, "Unexpected row data after appending a row");
  }
  
} END_TEST

START_TEST(test_matrix_append_col) {
  kld_vector_t * v = (kld_vector_t *) new_vector();

  int i; 
  for(i = 0; i < 10; i++) {
    char *buf = calloc(256, sizeof(char));
    sprintf(buf, "test-%d", i);
    vector_append(v, buf);
  }

  kld_matrix_t * m = (kld_matrix_t *) new_matrix();
  matrix_append_col(m, v);
  
  fail_if(m->cols_bounds != 1, "Cols bounds were not updated after appending col.");
  fail_if(m->cols_capacity != DEFAULT_MATRIX_COLS_CAPACITY, "Unexpected cols capacity after appending a col.");

  for(i = 0; i < 10; i++) {
    char *buf = calloc(256, sizeof(char));
    sprintf(buf, "test-%d", i);
    fail_if(strcmp(vector_get(m->cols[0], i), buf) != 0, "Unexpected col data after appending a col");
    fail_if(strcmp(vector_get(m->rows[i], 0), buf) != 0, "Unexpected row data after appending a col");
  }
  
} END_TEST

START_TEST(test_matrix_get) {
  kld_matrix_t * m = (kld_matrix_t *) new_matrix();

  int i, j; 
  for(i = 0; i < 10; i++) {
    kld_vector_t * v = (kld_vector_t *) new_vector();

    for(j = 0; j < 10; j++) {
      char *buf = calloc(256, sizeof(char));
      sprintf(buf, "test-%d-%d", i, j);
      vector_append(v, buf);
    }

    matrix_append_row(m, v);
  }
 
  char * data = (char *) matrix_get(m, 5, 5);
  char * buf = "test-5-5";
  fail_if(strcmp((char*) data, buf) != 0, "Unexpected get data after appending many rows.");
} END_TEST

Suite * new_matrix_suite() {
  Suite * s = suite_create("matrix");
  
  TCase * tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_new_matrix);

  tcase_add_test(tc_core, test_matrix_is_empty);

  tcase_add_test(tc_core, test_matrix_append_row);

  tcase_add_test(tc_core, test_matrix_get_row);

  tcase_add_test(tc_core, test_matrix_append_col);

  tcase_add_test(tc_core, test_matrix_get_col);

  tcase_add_test(tc_core, test_matrix_get);

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
