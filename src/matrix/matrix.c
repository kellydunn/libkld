#include <stdlib.h>
#include "matrix.h"

kld_matrix_t * new_matrix() {
  kld_matrix_t * m = calloc(1, sizeof(kld_matrix_t *));
  m->data = NULL;
  return m;
}

kld_vector_t * matrix_get_row(kld_matrix_t * m, int y) {
  return m->data[y];
}

kld_vector_t * matrix_get_col(kld_matrix_t * m, int x) {
  kld_vector_t * res = (kld_vector_t *) new_vector();
  
  // TODO Oof, O(N) for getting a column?  
  //      Lets research to see if we can do better.
  int i;
  for(i = 0; i < m->y_bounds; i++) {
    vector_append(res, vector_get(matrix_get_row(m, i), x));
  }

  return res;
}

void * matrix_get(kld_matrix_t * m, int x, int y) {
  return vector_get(matrix_get_row(m, y), x);
}

void matrix_add(kld_matrix_t * m, int x, int y, void * data) {
  kld_vector_t * v = matrix_get_row(m, y);
  // add at specific index in other vector
}
