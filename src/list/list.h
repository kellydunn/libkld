#ifndef _KLD_LIST_H
#define _KLD_LIST_H

#include "../common/common.h"

typedef struct kld_list kld_list_t;
typedef struct kld_list_node kld_list_node_t;

struct kld_list {
  int size;
  kld_list_node_t * head;
  kld_list_node_t * tail;
};

struct kld_list_node {
  void * data;
  kld_list_node_t * next;
  kld_list_node_t * prev;
};

kld_list_t * new_list();
void list_init(kld_list_t * list);
bool is_empty(kld_list_t * list);

void list_append(kld_list_t * list, void * val);
kld_list_node_t * list_pop(kld_list_t * list);
kld_list_t * list_reverse(kld_list_t * list);

void list_init_with_one(kld_list_t *list, kld_list_node_t * node);
void list_nuke(kld_list_t * list);
#endif
