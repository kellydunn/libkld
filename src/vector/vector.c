#include <stdlib.h>
#include <string.h>
#include "vector.h"

const int DEFAULT_VECTOR_CAPACITY = 10;

kld_vector_t * new_vector() {
  // TODO Implement
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

void * vector_get(kld_vector_t *v, int i) {
  return v->data[i];
}

void vector_insert(kld_vector_t * v, void * data) {
  if(vector_is_empty(v)) {
    v->data = malloc(sizeof(void*) * DEFAULT_VECTOR_CAPACITY);
  }

  // Grow if at capacity
  if(v->size == v->capacity) {
    v->capacity *= 2;
    v->data = realloc(v->data, sizeof(void *) * v->capacity);
  }

  v->data[v->size] = data;
  v->size++;
}

void vector_remove(kld_vector_t * v, int index) {
  // TODO Implement
}
