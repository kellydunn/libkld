#ifndef _KLD_MATRIX_H
#define _KLD_MATRIX_H

#include "../vector/vector.h"

typedef struct kld_matrix kld_matrix_t;

struct kld_matrix {
  kld_vector_t ** data;
};

kld_matrix_t * new_matrix();
kld_vector_t * matrix_get_col(int x);
kld_vector_t * matrix_get_row(int y);
void * matrix_get(int x, int y);

#endif
