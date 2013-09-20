#include <stdlib.h>
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

void * vector_data_at(kld_vector_t *v, int index) {
  // TODO Implement
  return NULL;
}

void vector_insert(kld_vector_t * v, void * data) {
  // TODO Implement
}

void vector_remove(kld_vector_t * v, int index) {
  // TODO Implement
}
