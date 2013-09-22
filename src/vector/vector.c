#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

const int DEFAULT_VECTOR_CAPACITY = 10;

kld_vector_t * new_vector() {
  kld_vector_t * v = (kld_vector_t *) calloc(1, sizeof(kld_vector_t*));
  v->size = 0;
  v->capacity = DEFAULT_VECTOR_CAPACITY;
  v->data = NULL;
  return v;
}

bool vector_is_empty(kld_vector_t *v) {
  // TODO A Vector shouldn't get into a state where these two would diverge
  //      But until I can implement the rest, this should be robust enough for the tests.
  return v->size == 0 && v->data == NULL;
}

void vector_grow(kld_vector_t * v) {
  v->capacity *= 2;
  v->data = (void **) realloc(v->data, sizeof(void *) * v->capacity);
}

void * vector_get(kld_vector_t *v, int i) {
  return v->data[i];
}

void vector_insert_at(kld_vector_t * v, int i, void * data) {
  if(vector_is_empty(v)) {
    v->data = (void **) malloc(sizeof(void*) * DEFAULT_VECTOR_CAPACITY);
  }

  if (i > v->size) {
    // If the desired index is outside of our current size
    // We need to fill the vector up to the desired index point
    // Then insert the value we want.
    int idx;
    for(idx = v->size; idx < i; idx++) {

      // Grow if at capacity
      // TODO The following six lines could be refactored 
      //      with the others below.
      if(v->size == v->capacity) {
        vector_grow(v);
      }

      v->data[v->size] = NULL;
      v->size++;
    }

  } else {
    // If the desired index is within our current size
    // We want to shift all the values after the insertion point to the right.
    // Then insert our desired value.
    int idx;
    for(idx = v->size; idx > i; idx--) {
      v->data[idx] = v->data[idx-1];
    }
  }

  // Grow if at capacity
  // TODO The following six lines could be refactored 
  //      with the others above.
  if(v->size == v->capacity) {
    vector_grow(v);
  }

  v->data[i] = data;
  v->size++;
}

void vector_append(kld_vector_t * v, void * data) {
  vector_insert_at(v, v->size, data);
}

void vector_remove_at(kld_vector_t * v, int i) {
  v->data[i] = NULL;

  // Shuffle elements down
  int idx;
  for(idx = i; idx < v->size-1; idx++) {
    v->data[idx] = v->data[idx+1];
  } 

  v->size--;

  if(v->size == 0) {
    v->data = NULL;
  } else if (v->size * 2 < v->capacity && v->capacity > DEFAULT_VECTOR_CAPACITY) {
    v->capacity /= 2;
    v->data = (void **) realloc(v->data, sizeof(void *) * v->capacity);
  }
}
