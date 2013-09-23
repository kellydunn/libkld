#ifndef _KLD_MATRIX_H
#define _KLD_MATRIX_H

#include "../vector/vector.h"

typedef struct kld_matrix kld_matrix_t;

/*
 * A Somewhat Non Standard Implementation of a matrix
 *
 * The current design of this matrix is to use two collections of <kld_vector_t>, 
 * one to represent all the rows inside of the <kld_matrix_t> and another to represent all the colums.
 * This effectively doubles the memory footprint of a <kld_matrix_t>, requiring 2 bytes for each entry.
 * However, due to the underlying implementation of a <kld_vector_t>, 
 * we can now garuntee constant time operations for retrieving single elements inside of the <kld_matrix_t> 
 * as well as entire rows and columns.
 * It should be noted that adding operations have an ammortized constant speed, but if the underlying <kld_vector_t>
 * need to grow, they will have to reallocate memory accordingly.  Inserting rows or colums in such a scenario could
 * cause adding operations to be O(rc), where **r** is the number of rows and **c** is the number of columns.
 */
struct kld_matrix {
  kld_vector_t ** rows;
  kld_vector_t ** cols;
  int rows_capacity;
  int cols_capacity;
  int rows_bounds;
  int cols_bounds;
};

extern const int DEFAULT_MATRIX_ROWS_CAPACITY;
extern const int DEFAULT_MATRIX_COLS_CAPACITY;

/* Creates and returns a new <kld_matrix_t>
 *
 * @return a pointer to a new <kld_matrix_t>
 */
kld_matrix_t * new_matrix();


/* Returns whether or not a matrix is empty
 * @m the <kld_matrix_t> in which to test for emptiness.
 *
 * @return true if the matrix is empty, and false if otherwise.
 */
bool matrix_is_empty(kld_matrix_t * m);


/* Appends a row **r** to <kld_matrix> **m**. In addition to appending, this operation will grow the columns of the matrix and append the values to each column as they are listed in the row **r**.
 * @m the <kld_matrix_t> in which to append the row **r**.
 * @r the <kld_vector_t> in which to append to the <kld_matrix_t> **m**.
 */
void matrix_append_row(kld_matrix_t * m, kld_vector_t * r);


/* Appends a column **c** to <kld_matrix> **m**. In addition to appending, this operation will grow the rows of the matrix and append the values to each row as they are listed in the column **c**.
 * @m the <kld_matrix_t> in which to append the column **c**.
 * @c the <kld_vector_t> in which to append to the <kld_matrix_t> **m**.
 */
void matrix_append_col(kld_matrix_t * m, kld_vector_t * c);


/* Returns the column at position **x** in the <kld_matrix> **m**.
 * @m the <kld_matrix_t> in which to retrieve the column.
 * @x the index in which to retrieve the column
 *
 * @return the column at index **x** as a <kld_vector_t> 
 */
kld_vector_t * matrix_get_col(kld_matrix_t * m, int x);


/* Returns the row at position **y** in the <kld_matrix> **m**.
 * @m the <kld_matrix_t> in which to retrieve the row.
 * @y the index in which to retrieve the row
 *
 * @return the row at index **y** as a <kld_vector_t> 
 */
kld_vector_t * matrix_get_row(kld_matrix_t * m, int y);


/* Returns the data at [**x**, **y**] in <kld_matrix> **m**.
 * @m the <kld_matrix_t> in which to retrieve the data.
 * @x the column position in which to retrieve the data in <kld_matrix_t> **m**.
 * @y the row position in which to retrieve the data in <kld_matrix_t> **m**.
 *
 * @return the data at [**x**, **y**] in <kld_matrix> **m**.
 */
void * matrix_get(kld_matrix_t * m, int x, int y);

#endif
