#ifndef _KLD_NARY_TREE_H
#define _KLD_NARY_TREE_H

#include "../common/common.h"
#include "../vector/vector.h"

typedef struct kld_nary_tree kld_nary_tree_t;
typedef struct kld_nary_tree_node kld_nary_tree_node_t;

struct kld_nary_tree {
  kld_nary_tree_node_t * root;
  int degree;
  int size;
};

kld_nary_tree_t *  new_nary_tree(int degree);

struct kld_nary_tree_node {
  kld_nary_tree_node_t * parent;
  kld_vector_t * children; // TODO I guess we could just use arrays since we're restricting them to n
  kld_vector_t * siblings; // TODO Determine if needed
};

#endif 
