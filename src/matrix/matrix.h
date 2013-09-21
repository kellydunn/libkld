#ifndef _KLD_MATRIX_H
#define _KLD_MATRIX_H

#include "../vector/vector.h"

typedef struct kld_matrix kld_matrix_t;

struct kld_matrix {
  kld_vector_t ** data;
  int x_bounds;
  int y_bounds;
};

kld_matrix_t * new_matrix();
void matrix_append_row(kld_matrix_t * m, kld_vector_t * v);
kld_vector_t * matrix_get_col(kld_matrix_t * m, int x);
kld_vector_t * matrix_get_row(kld_matrix_t * m, int y);
void * matrix_get(kld_matrix_t * m, int x, int y);
void matrix_add(kld_matrix_t * m, int x, int y, void * data);
void matrix_remove(kld_matrix_t * m, int x, int y);

#endif
