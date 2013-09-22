#ifndef _KLD_LIST_H
#define _KLD_LIST_H

#include "../common/common.h"

typedef struct kld_list kld_list_t;
typedef struct kld_list_node kld_list_node_t;

/* 
 * A Standard List implementation.
 *
 * <kld_list_t> is implemented as a doubly-linked circular linked list.
 * It's flexible in that it can serve as a stack or as a queue in addition to a linked list by calling 
 * `list_append` then `list_pop` (for FILO operations), and `list_append` then `list_shift` (for FIFO operations) respectively.
 *
 * ###operation times
 *
 * | shift / pop | prepend / append | search | reverse | 
 * | ----------- | ---------------- | ------ | ------- |
 * | O(1)        | O(1)             | O(n)*  | O(n)    |
 *
 * (* is worst-case scenario)
 *
 */
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

/* 
 * Creates a new <kld_list_t>
 * @return a pointer to a new <kld_list_t>
 */
kld_list_t * new_list();


void list_init(kld_list_t * list);


/* 
 * Checks to see if a list is empty.
 * @list the list to be checked.
 * @return true if the list is empty, false otherwise.
 */
bool list_is_empty(kld_list_t * list);


/* 
 * Appends data to a list
 * @list the list to append data to.
 * @data the data to append to the list.
 */
void list_append(kld_list_t * list, void * data);


/* 
 * Removes and returns the last <kld_list_node_t> in the <kld_list_t>.
 * @list the list to pop the last element from.
 * @return <kld_list_node_t> in the passed in list.
 */
kld_list_node_t * list_pop(kld_list_t * list);


/* 
 * Returns a reversed copy of the passed in list.
 * @list the <kld_list_t> to be reversed.
 * @return a new <kld_list_t> that is the reversed value of the passed in one.
 */
kld_list_t * list_reverse(kld_list_t * list);


/* 
 * Removes and returns the first <kld_list_node_t> in the <kld_list_t>.
 * @list the <kld_list_t> in which to remove the first <kld_list_node_t> from.
 * @return the first <kld_list_node_t> in the passed in <kld_list_t>
 */
kld_list_node_t * list_shift(kld_list_t * list);

void list_init_with_one(kld_list_t *list, kld_list_node_t * node);

/*
 * Removes
 *
 */
void list_clear(kld_list_t * list);
#endif
