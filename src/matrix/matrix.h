#ifndef _KLD_MATRIX_H
#define _KLD_MATRIX_H

#include "../vector/vector.h"

typedef struct kld_matrix kld_matrix_t;

/*
 * A Somewhat Non Standard Implementation of a matrix
 *
 * The current design of this matrix is to use two collections of <kld_vector_t>, one to represent all the rows inside of the <kld_matrix_t> and another to represent all the colums.
 * This effectively doubles the memory footprint of a <kld_matrix_t>, requiring 2 bytes for each entry.
 * However, due to the underlying implementation of a <kld_vector_t>, we can now garuntee constant time operations for retrieving single elements inside of the <kld_matrix_t> as well as entire rows and columns.
 */
struct kld_matrix {
  kld_vector_t ** rows;
  kld_vector_t ** cols;
  int x_bounds;
  int y_bounds;
  int capacity;
};

extern const int DEFAULT_MATRIX_CAPACITY;

kld_matrix_t * new_matrix();
bool matrix_is_empty();
kld_vector_t * matrix_get_col(kld_matrix_t * m, int x);
kld_vector_t * matrix_get_row(kld_matrix_t * m, int y);
void * matrix_get(kld_matrix_t * m, int x, int y);
void matrix_insert_at(kld_matrix_t * m, int x, int y, void * data);
void matrix_remove_at(kld_matrix_t * m, int x, int y);
void matrix_append_row(kld_matrix_t * m, kld_vector_t * r);
void matrix_append_col(kld_matrix_t * m, kld_vector_t * c);

#endif
