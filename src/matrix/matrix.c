#include <stdlib.h>
#include "matrix.h"

kld_matrix_t * new_matrix() {
  kld_matrix_t * m = calloc(1, sizeof(kld_matrix_t *));
  m->data = NULL;
  m->y_bounds = 0;
  m->x_bounds = 0;
  return m;
}

void matrix_append_col(kld_matrix_t * m, kld_vector_t * v) {
  vector_append(*m->data, v);
}

kld_vector_t * matrix_get_row(kld_matrix_t * m, int y) {
  // TODO Implement
  return NULL;
}

kld_vector_t * matrix_get_col(kld_matrix_t * m, int x) {
  return m->data[x];
}

void * matrix_get(kld_matrix_t * m, int x, int y) {
  return vector_get(matrix_get_col(m, x), y);
}

void matrix_add(kld_matrix_t * m, int x, int y, void * data) {
  // TODO Implement
}

void matrix_remove(kld_matrix_t * m, int x, int y) {
  // TODO Implement
}
