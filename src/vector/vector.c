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

bool is_empty(kld_vector_t *v) {
  // TODO Implement
  return false;
}

void * data_at(kld_vector_t *v, int index) {
  // TODO Implement
  return NULL;
}

void insert(kld_vector_t * v, void * data) {
  // TODO Implement
}

void remove(kld_vector_t * v, int index) {
  // TODO Implement
}
