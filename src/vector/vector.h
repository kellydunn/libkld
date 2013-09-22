#ifndef _KLD_VECTOR_H
#define _KLD_VECTOR_H

#include "../common/common.h"

typedef struct kld_vector kld_vector_t;

struct kld_vector {
  void ** data;
  int size;
  int capacity;
};

extern const int DEFAULT_VECTOR_CAPACITY;

kld_vector_t * new_vector();
bool vector_is_empty(kld_vector_t * v);
void * vector_get(kld_vector_t * v, int i);
void vector_insert_at(kld_vector_t * v, int i, void * data);
void vector_append(kld_vector_t * v, void * data);
void vector_remove_at(kld_vector_t * v, int i);

#endif 
