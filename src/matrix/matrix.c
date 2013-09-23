#include <stdlib.h>
#include "matrix.h"

const int DEFAULT_MATRIX_ROW_CAPACITY = 10;
const int DEFAULT_MATRIX_COL_CAPACITY = 10;

kld_matrix_t * new_matrix() {
  kld_matrix_t * m = (kld_matrix_t *) calloc(1, sizeof(kld_matrix_t));

  m->rows = NULL;
  m->cols = NULL;
  
  m->row_capacity = 0;
  m->col_capacity = 0;

  m->row_bounds = 0;
  m->col_bounds = 0;
  return m;
}

bool matrix_is_empty(kld_matrix_t * m) {
  return m->rows == NULL  && m->cols == NULL;
}

void matrix_append_row(kld_matrix_t * m, kld_vector_t * r) {

} 
