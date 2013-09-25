#include <stdlib.h>
#include <check.h>
#include "../../src/graph/graph.h"

START_TEST(test_new_graph) {
  kld_graph_t * g = (kld_graph_t *) new_graph();
  fail_if(g->adj_matrix != NULL, "Unexpected matrix upon initialization");
} END_TEST

START_TEST(test_graph_is_empty) {
  kld_graph_t * g = (kld_graph_t *) new_graph();
  fail_if(!graph_is_empty(g), "Graph is not empty upon initialization");
} END_TEST

START_TEST(test_graph_node_is_adjacent) {
  kld_graph_t * g = (kld_graph_t *) new_graph();

  int data = 1;

  kld_graph_node_t * n1 = (kld_graph_node_t *) new_graph_node(g);
  kld_graph_node_t * n2 = (kld_graph_node_t *) new_graph_node(g);

  kld_vector_t * v = new_vector();
  vector_append(v, NULL);
  vector_append(v, &data);
  matrix_append_row(g->adj_matrix, v);

  kld_vector_t * v2 = new_vector();
  vector_append(v2, &data);
  vector_append(v2, NULL);
  matrix_append_row(g->adj_matrix, v2);

  fail_if(graph_is_empty(g), "Graph should not be empty upon initialization");
  fail_if(!graph_node_is_adjacent(g, n1, n2), "Nodes are not adjacent when expected to be");
} END_TEST

Suite * new_graph_suite() {
  Suite * s = suite_create("graph");

  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_new_graph);

  tcase_add_test(tc_core, test_graph_is_empty);

  tcase_add_test(tc_core, test_graph_node_is_adjacent);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int num_failed = 0;

  Suite * graph_suite = new_graph_suite();
  SRunner * graph_suite_runner = srunner_create(graph_suite);

  srunner_run_all(graph_suite_runner, CK_NORMAL);
  num_failed = srunner_ntests_failed(graph_suite_runner);

  srunner_free(graph_suite_runner);

  return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
