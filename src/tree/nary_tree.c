#include <stdlib.h>
#include "nary_tree.h"

kld_nary_tree_t * new_nary_tree(int degree) {
  kld_nary_tree_t * t = (kld_nary_tree_t *) calloc(1, sizeof(kld_nary_tree_t));
  t->degree = degree;
  t->root = NULL;
  return t;
}
