#include "stdlib.h"
#include "list.h"

// @return {kld_list_t*} list.  A new list.
kld_list_t * new_list() {
  kld_list_t * list = (kld_list_t *) calloc(1, sizeof(kld_list_t));
  list_init(list);
  return list;
}

void list_init(kld_list_t * list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

// Places the passed in val at the begining of the list
void list_prepend(kld_list_t * list, void * val) {
  kld_list_node_t * tmp = (kld_list_node_t *) calloc(1, sizeof(kld_list_node_t));

  tmp->data = val;

  tmp->next = (kld_list_node_t*) list->head;
  list->head = (kld_list_node_t*) tmp;
  tmp->prev = (kld_list_node_t*) list->tail;

  list->size++;
}

// Removes and returns the first element in the list
kld_list_node_t * list_shift(kld_list_t * list) {
  kld_list_node_t * tmp = (kld_list_node_t *) calloc(1, sizeof(kld_list_node_t));
  
  tmp = (kld_list_node_t*) list->head;
  list->head = (kld_list_node_t*) list->head->next;
  list->head->prev = (kld_list_node_t*) list->tail;
  
  tmp->next = NULL;
  tmp->prev = NULL;

  list->size--;
  return tmp;
}

// Places the passed in val at the end of the list
void list_append(kld_list_t * list, void * val) {
  kld_list_node_t * tmp = (kld_list_node_t *) calloc(1, sizeof(kld_list_node_t));

  tmp->data = val;

  if(list_is_empty(list)) {
    list_init_with_one(list, tmp);
   } else {
    list->tail->next = tmp;
    tmp->prev = (kld_list_node_t*) list->tail;
    tmp->next = (kld_list_node_t*) list->head;
    list->tail = tmp;
  }

  list->size++;
}

// Removes and returns the last element in the list
kld_list_node_t * list_pop(kld_list_t * list) {
  kld_list_node_t * tmp = (kld_list_node_t * ) calloc(1, sizeof(kld_list_node_t));

  if(list_is_empty(list)) {
    return NULL;
  } else {    
    tmp = (kld_list_node_t *) list->tail;

    if(list->size == 1) {
      list_clear(list);
    } else {
      list->tail = (kld_list_node_t*) list->tail->prev;
      list->tail->next = (kld_list_node_t*) list->head;
    }

    tmp->next = NULL;
    tmp->prev = NULL;

    list->size--;
    return tmp;
  }
}

kld_list_t * list_reverse(kld_list_t * list) {
  kld_list_node_t * current = list->head;
  kld_list_node_t * tmp = current;
  kld_list_node_t * rev = NULL;

  // We have to check against tail because the list is circular
  while(current != NULL && rev != list->tail) {
    tmp = current->next;
    current->next = rev;
    rev = current;
    current = tmp;
  }

  kld_list_t * res = new_list();
  res->head = rev;

  return res;
} 

// Returns whether or not the list has no nodes
bool list_is_empty(kld_list_t * list) {
  return (list->head == NULL && list->tail == NULL);
}

// Initializes the list to have a single node
void list_init_with_one(kld_list_t * list, kld_list_node_t * node) {
  list->head = node;
  list->tail = node;

  list->head->next = list->tail;
  list->head->prev = list->tail;

  list->tail->next = list->head;
  list->tail->prev = list->head;
}

// Completely clears list
void list_clear(kld_list_t * list) {
  list->tail = NULL;
  list->head = NULL;  
}
