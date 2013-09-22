#include "stdlib.h"
#include "list.h"

kld_list_t * new_list() {
  kld_list_t * list = (kld_list_t *) calloc(1, sizeof(kld_list_t));
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void list_prepend(kld_list_t * list, void * val) {
  kld_list_node_t * tmp = (kld_list_node_t *) calloc(1, sizeof(kld_list_node_t));

  tmp->data = val;

  // TODO Consider tail
  //      And what happens when list is empty
  tmp->next = (kld_list_node_t*) list->head;
  list->head = (kld_list_node_t*) tmp;
  tmp->prev = (kld_list_node_t*) list->tail;

  list->size++;
}

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

void list_append(kld_list_t * list, void * val) {
  kld_list_node_t * tmp = (kld_list_node_t *) calloc(1, sizeof(kld_list_node_t));

  tmp->data = val;

  // TODO Both of these code paths have 
  //      similar operations.  REFACTOR!
  if(list_is_empty(list)) {
    tmp->prev = (kld_list_node_t *) list->tail;
    list->tail = (kld_list_node_t *) tmp;
    tmp->next = (kld_list_node_t *) list->head;
    list->head = (kld_list_node_t *) tmp;
   } else {
    list->tail->next = tmp;
    tmp->prev = (kld_list_node_t*) list->tail;
    tmp->next = (kld_list_node_t*) list->head;
    list->tail = tmp;
  }

  list->size++;
}

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

bool list_is_empty(kld_list_t * list) {
  return (list->head == NULL && list->tail == NULL);
}

void list_clear(kld_list_t * list) {
  list->tail = NULL;
  list->head = NULL;  
}
