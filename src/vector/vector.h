#ifndef _KLD_VECTOR_H
#define _KLD_VECTOR_H

#include "../common/common.h"

typedef struct kld_vector kld_vector_t;

struct kld_vector {
  void * data;
  int size;
  int capacity;
};

extern const int DEFAULT_VECTOR_CAPACITY;

kld_vector_t * new_vector();
bool is_empty(kld_vector_t * v);
void * data_at(kld_vector_t * v, int index);
void insert(kld_vector_t * v, void * data);
void remove(kld_vector_t * v, int index);

#endif 
