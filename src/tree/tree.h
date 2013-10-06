#ifndef _KLD_NARY_TREE_H
#define _KLD_NARY_TREE_H

#include "../common/common.h"
#include "../list/list.h"
#include "../vector/vector.h"

typedef struct kld_tree kld_tree_t;
typedef struct kld_tree_node kld_tree_node_t;

/* A standard k-nary tree implementation.
 *
 */
struct kld_tree {
  kld_tree_node_t * root;
  int num_children;
  int size;
};

kld_tree_t *  new_tree(int degree);
void tree_heap_ordered_insert(kld_tree_t * t, unsigned char * key, void * data);

struct kld_tree_node {
  unsigned char * key; 
  void * data;
  kld_tree_node_t * parent;
  kld_vector_t * children; 
  kld_vector_t * siblings; 
};

kld_tree_node_t * new_tree_node(unsigned char * key, void * data);

#endif 
