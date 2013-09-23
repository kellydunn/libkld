#ifndef _KLD_VECTOR_H
#define _KLD_VECTOR_H

#include "../common/common.h"

typedef struct kld_vector kld_vector_t;

/*
 * A Standard implemetation of a Vector.
 * 
 * <kld_vector_t> is most similar to an array list, or a dynamic array.  It grows and shrinks according to the number of its elements.
 * As to 
 */
struct kld_vector {
  void ** data;
  int size;
  int capacity;
};

extern const int DEFAULT_VECTOR_CAPACITY;

/* Creates and returns a pointer to a new <kld_vector_t>
 *
 * @return a pointer to a new <kld_vector_t>
 */
kld_vector_t * new_vector();


/* Returns whether or not the vector is empty
 * @v the vector in which to check emptiness.
 *
 * @return true if the vector has no elements or false if otherwise.
 */
bool vector_is_empty(kld_vector_t * v);


/* Returns the data stored at the index **i** inside of <kld_vector_t> **v**.
 * @v the <kld_vector_t> in which to get data.
 * @i the index of the <kld_vector_t> in which to get data.
 *
 * @return the data stored at index **i** of <kld_vector_t> **v** passed in.
 */
void * vector_get(kld_vector_t * v, int i);

/* Inserts the passed in **data** at index **i** in vector **v**.
 * @v the <kld_vector_t> in which to insert the **data**.
 * @i the index in which to insert into <kld_vector_t> **v**.
 * @data the data in which to insert into <kld_vector_t> **v**.
 */
void vector_insert_at(kld_vector_t * v, int i, void * data);

/* Appends the passed in **data** to vector **v**.
 * @v the <kld_vector_t> in which to insert the **data**.
 * @data the data in which to append into <kld_vector_t> **v**.
 */
void vector_append(kld_vector_t * v, void * data);

/* Removes the passed in **data** at index **i** in vector **v**.
 * @v the <kld_vector_t> in which to remove the **data**.
 * @i the index in which to remove into <kld_vector_t> **v**.
 * @data the data in which to remove into <kld_vector_t> **v**.
 */
void vector_remove_at(kld_vector_t * v, int i);

#endif 
