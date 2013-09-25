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
  }

  if(m->rows_bounds == m->rows_capacity) {
    matrix_grow_rows(m);
  }
  
  // Keep Growing if our capacity is underneath the length of the row we're adding.
  while(r->size >= m->cols_capacity) {
    matrix_grow_cols(m);
  }

  // Set the bounds of the colums to the size of the row if the current bounds is less than the length of the row.
  if(r->size > m->cols_bounds) {
    m->cols_bounds = r->size;
  }

  // Insert row
  m->rows[m->rows_bounds] = r;
  
  // Append to all columns
  int i;
  for(i = 0; i < r->size; i++) {
    if(m->cols[i] == NULL) {
      m->cols[i] = new_vector();
    }

    vector_append(m->cols[i], vector_get(r, i));
  }
  
  // Increment row bounds
  m->rows_bounds++;
}

void matrix_append_col(kld_matrix_t * m, kld_vector_t * c) {
  if(matrix_is_empty(m)) {
    m->rows = (kld_vector_t **) calloc(DEFAULT_MATRIX_ROWS_CAPACITY, sizeof(kld_vector_t *));
    m->cols = (kld_vector_t **) calloc(DEFAULT_MATRIX_COLS_CAPACITY, sizeof(kld_vector_t *));
  }

  if(m->cols_bounds == m->cols_capacity) {
    matrix_grow_cols(m);
  }
  
  // Keep Growing if our capacity is underneath the length of the col we're adding.
  while(c->size >= m->rows_capacity) {
    matrix_grow_rows(m);
  }

  // Set the bounds of the rows to the size of the col if the current bounds is less than the length of the col.
  if(c->size > m->rows_bounds) {
    m->rows_bounds = c->size;
  }

  // Insert col
  m->cols[m->cols_bounds] = c;
  
  // Append to all rows accordingly
  int i;
  for(i = 0; i < c->size; i++) {
    if(m->rows[i] == NULL) {
      m->rows[i] = new_vector();
    }

    vector_append(m->rows[i], vector_get(c, i));
  }
  
  // Increment row bounds
  m->cols_bounds++;
}

kld_vector_t * matrix_get_col(kld_matrix_t * m, int x) {
  return m->cols[x];
}

kld_vector_t * matrix_get_row(kld_matrix_t * m, int y) {
  return m->rows[y];
}

void * matrix_get(kld_matrix_t * m, int x, int y) {
  // TODO This is rather hacky, investigate why this is an issue and solve it.
  if(m->cols[x] == NULL) {
    return NULL; 
  }

  return vector_get(m->cols[x], y);
}

void matrix_set(kld_matrix_t * m, int x, int y, void * data) {
  // TODO Refactor
  if(matrix_is_empty(m)) {
    m->rows = (kld_vector_t **) calloc(DEFAULT_MATRIX_ROWS_CAPACITY, sizeof(kld_vector_t *));
    m->cols = (kld_vector_t **) calloc(DEFAULT_MATRIX_COLS_CAPACITY, sizeof(kld_vector_t *));
  }

  // Keep Growing if our capacity is underneath the length of the col we're adding.
  while(x >= m->rows_capacity) {
    matrix_grow_rows(m);
  }

  // Keep Growing if our capacity is underneath the length of the row we're adding.
  while(y >= m->cols_capacity) {
    matrix_grow_cols(m);
  }

  // TODO This is kind of hacky; refactor to handle garuntees
  if(m->cols[x] == NULL) {
    m->cols[x] = new_vector();
  }

  // TODO This is kind of hacky; refactor to handle garuntees
  if(m->rows[y] == NULL) {
    m->rows[y] = new_vector();
  }

  vector_set(m->cols[x], y, data);
  vector_set(m->rows[y], x, data);

  if(x > m->cols_bounds) {
    m->cols_bounds = x;
  }

  if(y > m->rows_bounds) {
    m->rows_bounds = y;
  }
}
