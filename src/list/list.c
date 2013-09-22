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

  // TODO Both of these code paths have 
  //      similar operations.  REFACTOR!
  if(list_is_empty(list)) {
    tmp->next = list->head;
    list->head = tmp;
    tmp->prev = list->tail;
    list->tail = tmp;
   } else {
    list->head->prev = tmp;
    tmp->next = list->head;
    tmp->prev = list->tail;
    list->head = tmp;
  }

  list->size++;
}

kld_list_node_t * list_pop(kld_list_t * list) {
  kld_list_node_t * tmp = (kld_list_node_t * ) calloc(1, sizeof(kld_list_node_t));

  // TODO These operations are pretty similar to list_shift
  //      Potentially refactor
  if(list_is_empty(list)) {
    return NULL;
  } else {    
    tmp = list->tail;

    if(list->size == 1) {
      list_clear(list);
    } else {
      list->tail = list->tail->prev;
      list->tail->next = list->head;
    }

    tmp->next = NULL;
    tmp->prev = NULL;

    list->size--;
    return tmp;
  }
}

kld_list_node_t * list_shift(kld_list_t * list) {
  kld_list_node_t * tmp = (kld_list_node_t *) calloc(1, sizeof(kld_list_node_t));

  // TODO These operations are pretty similar to list_pop
  //      Potentially refactor
  if(list_is_empty(list)) {
    return NULL;
  } else {
    tmp = list->head;

    if(list->size == 1) {
      list_clear(list);
    } else {
      list->head = list->head->next;
      list->head->prev = list->tail;
    }

    tmp->next = NULL;
    tmp->prev = NULL;
    
    list->size--;
    return tmp;
  }
}

void list_append(kld_list_t * list, void * val) {
  kld_list_node_t * tmp = (kld_list_node_t *) calloc(1, sizeof(kld_list_node_t));

  tmp->data = val;

  // TODO Both of these code paths have 
  //      similar operations.  REFACTOR!
  if(list_is_empty(list)) {
    tmp->prev = list->tail;
    list->tail = tmp;
    tmp->next = list->head;
    list->head = tmp;
   } else {
    list->tail->next = tmp;
    tmp->prev = list->tail;
    tmp->next = list->head;
    list->tail = tmp;
  }

  list->size++;
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
