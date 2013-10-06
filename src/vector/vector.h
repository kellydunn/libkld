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

/* Sets the data of a vector element at index **i**
 * @v the <kld_vector_t> to set data
 * @i the index in which to set the data
 * @data the new data to set at element **i** inside of <kld_vector_t> **v**
 */
void vector_set(kld_vector_t * v, int i, void * data);

/* Sorts the elements of the <kld_vector_t> by the means of the quicksort algorithm.  Asserts that vector data comparable by using the < operator.
 * @v the <kld_vector_t> to sort.
 */
void vector_quicksort(kld_vector_t * v);

/* Swaps the element at index **i** with the element at index **j** inside of the <kld_vector_t> **v**
 * @v the <kld_vector_t> in which to swap the elements
 * @i the index **i** in which to swap elements inside of the <kld_vector_t>
 * @j the index **j** in which to swap elements inside of the <kld_vector_t>
 */
void vector_swap(kld_vector_t * v, int i, int j);

/* Partitions the <kld_vector_t> such that all elements contained in a subarray 
 * defined by bounds **left** and **right** that are less than or equal to the element at the **pivot** index are to the left of the **pivot** index
 * and all the elements greater than the element at the **pivot** index are to the right of the **pivot** index.
 * @v the <kld_vector_t> in which to partition.
 * @left the left bounds of the subarray in which to partition.
 * @right the right bounds of the subarray in which to partition.
 * @pivot the pivot index in which to partition the <kld_vector_t>.
 *
 * @return returns the new index of the pivoted elment after partitioning.
 */
int vector_partition(kld_vector_t * v, int left, int right, int pivot);

#endif 
