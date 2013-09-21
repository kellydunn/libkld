#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

const int DEFAULT_VECTOR_CAPACITY = 10;

kld_vector_t * new_vector() {
  kld_vector_t * v = calloc(1, sizeof(kld_vector_t*));
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
  v->data = realloc(v->data, sizeof(void *) * v->capacity);
}

void * vector_get(kld_vector_t *v, int i) {
  return v->data[i];
}

void vector_insert_at(kld_vector_t * v, int i, void * data) {
  if (i > v->size) {
    int idx;
    for(idx = v->size; idx < i; idx++) {
      v->data[v->size] = data;
      v->size++;
    }
  }

  if(vector_is_empty(v)) {
    v->data = malloc(sizeof(void*) * DEFAULT_VECTOR_CAPACITY);
  }

  // Grow if at capacity
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
    v->data = realloc(v->data, sizeof(void *) * v->capacity);
  }
}
