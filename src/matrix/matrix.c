#include <stdlib.h>
#include "matrix.h"

const int DEFAULT_MATRIX_ROWS_CAPACITY = 10;
const int DEFAULT_MATRIX_COLS_CAPACITY = 10;

kld_matrix_t * new_matrix() {
  kld_matrix_t * m = (kld_matrix_t *) calloc(1, sizeof(kld_matrix_t));

  m->rows = NULL;
  m->cols = NULL;
  
  m->rows_capacity = DEFAULT_MATRIX_ROWS_CAPACITY;
  m->cols_capacity = DEFAULT_MATRIX_COLS_CAPACITY;

  m->rows_bounds = 0;
  m->cols_bounds = 0;
  return m;
}

bool matrix_is_empty(kld_matrix_t * m) {
  return m->rows == NULL  && m->cols == NULL;
}

void matrix_grow_rows(kld_matrix_t * m) {
  m->rows_capacity *= 2;
  m->rows = (kld_vector_t **) realloc(m->rows, sizeof(kld_vector_t*) * m->rows_capacity);
}

void matrix_grow_cols(kld_matrix_t * m) {
  m->cols_capacity *= 2;
  m->cols = (kld_vector_t **) realloc(m->cols, sizeof(kld_vector_t*) * m->cols_capacity);
}

void matrix_append_row(kld_matrix_t * m, kld_vector_t * r) {
  if(matrix_is_empty(m)) {
    m->rows = (kld_vector_t **) calloc(DEFAULT_MATRIX_ROWS_CAPACITY, sizeof(kld_vector_t *));
    m->cols = (kld_vector_t **) calloc(DEFAULT_MATRIX_COLS_CAPACITY, sizeof(kld_vector_t *));
  } else {

    // TODO This could be synchronized or refactored with the check below
    if(m->rows_bounds == m->rows_capacity) {
      matrix_grow_rows(m);
    }

    // TODO This could be synchronized or refactored with the check above
    if(m->cols_bounds == m->cols_capacity) {
      matrix_grow_cols(m);
    }

    *(m->rows[m->rows_bounds]) = *r;
    
    int i;
    for(i = 0; i < m->cols_capacity; i++) {
      vector_append(m->cols[i], vector_get(r, i));
    }

    m->rows_bounds++;
  }
}
