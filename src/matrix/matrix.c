#include <stdlib.h>
#include "matrix.h"

const int DEFAULT_MATRIX_CAPACITY = 100;

kld_matrix_t * new_matrix() {
  kld_matrix_t * m = (kld_matrix_t *) calloc(1, sizeof(kld_matrix_t *));

  m->rows = NULL;
  m->cols = NULL;
  
  m->y_bounds = 0;
  m->x_bounds = 0;
  return m;
}

bool matrix_is_empty(kld_matrix_t * m) {
  return m->rows == NULL  && m->cols == NULL;
}
