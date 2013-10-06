#include <stdlib.h>
#include <check.h>
#include "../../src/tree/tree.h"

START_TEST (test_new_tree) {
  kld_tree_t * t = (kld_tree_t *) new_tree(1);
  fail_if(t->root != NULL, "Root of nary tree incorrectly set after initializiation.");
} END_TEST

START_TEST (test_tree_heap_ordered_insert) {
  kld_tree_t * t = (kld_tree_t *) new_tree(1);
  int data = 1;
  tree_heap_ordered_insert(t, (unsigned char *) "1", &data);
  fail_if(t->root == NULL, "Root is null after a single insert.");
  fail_if(t->root->key != (unsigned char * ) "1", "Root is null after a single insert.");
  fail_if(t->root->data != &data, "Root is null after a single insert.");
} END_TEST

START_TEST (test_tree_heap_ordered_insert2) {
  kld_tree_t * t = (kld_tree_t *) new_tree(1);
  int data = 1;
  tree_heap_ordered_insert(t, (unsigned char *) "2", &data);
  tree_heap_ordered_insert(t, (unsigned char *) "1", &data);

  fail_if(t->root == NULL, "Root is null after a single insert.");
  fail_if(strcmp((const char *) t->root->key, "1") != 0, "Root does not have the expected key value after inserting twice.");

  kld_tree_node_t * child = vector_get(t->root->children, 0);
  fail_if(strcmp((const char *) child->key, "2") != 0, "Root children does not have the expected key value after inserting twice.");
} END_TEST

START_TEST (test_tree_heap_ordered_insert3) {
  kld_tree_t * t = (kld_tree_t *) new_tree(2);
  int data = 1;
  tree_heap_ordered_insert(t, (unsigned char *) "3", &data);
  tree_heap_ordered_insert(t, (unsigned char *) "1", &data);
  tree_heap_ordered_insert(t, (unsigned char *) "2", &data);

  fail_if(t->root == NULL, "Root is null after a single insert.");
  fail_if(strcmp((const char *) t->root->key, "1") != 0, "Root does not have the expected key value after inserting three times.");

  kld_tree_node_t * child = vector_get(t->root->children, 0);
  kld_tree_node_t * child2 = vector_get(t->root->children, 1);
  fail_if(strcmp((const char *) child2->key, "2") != 0, "Root children does not have the expected key value after inserting three times.");
  fail_if(strcmp((const char *) child->key, "3") != 0, "Root children does not have the expected key value after inserting three times.");
} END_TEST

Suite * new_tree_suite() {
  Suite * s = suite_create("tree");

  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_new_tree);
  tcase_add_test(tc_core, test_tree_heap_ordered_insert);
  tcase_add_test(tc_core, test_tree_heap_ordered_insert2);
  tcase_add_test(tc_core, test_tree_heap_ordered_insert3);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int num_failed = 0;

  Suite * tree_suite = new_tree_suite();
  SRunner * tree_suite_runner = srunner_create(tree_suite);

  srunner_run_all(tree_suite_runner, CK_NORMAL);
  num_failed = srunner_ntests_failed(tree_suite_runner);

  srunner_free(tree_suite_runner);

  return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
