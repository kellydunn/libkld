#include <stdlib.h>
#include "tree.h"

kld_tree_t * new_tree(int num_children) {
  kld_tree_t * t = (kld_tree_t *) calloc(1, sizeof(kld_tree_t));
  t->num_children = num_children;
  t->root = NULL;
  t->size = 0;
  return t;
}

bool tree_is_empty(kld_tree_t * t) {
  return t->root == NULL && t->size == 0;
}

kld_tree_node_t * tree_heap_ordered_insert_recursive(kld_tree_t * t, kld_tree_node_t * current, unsigned char * key, void * data) {
  if(current == NULL) {  
    // Insert into root if root is null
    current = (kld_tree_node_t *) new_tree_node(key, data);

  } else if(byte_cmp(current->key, key) > 0) {
    // If the current key is less than our desired insertion point
    // make a new node, and 
    kld_tree_node_t * n = (kld_tree_node_t *) new_tree_node(key, data);
    n->children = (kld_vector_t *) new_vector();
    vector_append(n->children, current);
    current->parent = n;
    current = n;

  } else {
    // Otherwise if the current key is greater than zero and we 
    // need to find an insertion point in the children

    // If children are null, we have to make them.
    if(current->children == NULL) {
      current->children = (kld_vector_t *) new_vector();
    }

    if(current->children->size < t->num_children) {
      kld_tree_node_t * n = (kld_tree_node_t *) new_tree_node(key, data);
      vector_append(current->children, n);
    } else {
      // Iterate through children left to right and try to find insertion point.
      int i;
      for(i = 0; i < t->num_children; i++) {
        kld_tree_node_t * child = (kld_tree_node_t *) vector_get(current->children, i);
        tree_heap_ordered_insert_recursive(t, child , key, data);
      }
    }
  }

  return current;
}

void tree_heap_ordered_insert(kld_tree_t * t, unsigned char * key, void * data) {
  t->root = (kld_tree_node_t *) tree_heap_ordered_insert_recursive(t, t->root, key, data);
}

kld_tree_node_t * new_tree_node(unsigned char * key, void * data) {
  kld_tree_node_t * n = (kld_tree_node_t *) calloc(1, sizeof(kld_tree_node_t));
  n->data = data;
  n->key = key;
  n->parent = NULL;
  n->children = NULL;
  n->siblings = NULL;
  return n;
}
