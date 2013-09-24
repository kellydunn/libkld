#include <stdlib.h>
#include <check.h>
#include "../../src/graph/graph.h"

START_TEST(test_new_graph) {
  kld_graph_t * g = (kld_graph_t *) new_graph();
  fail_if(g->adj_matrix != NULL, "Unexpected matrix upon initialization");
} END_TEST

Suite * new_graph_suite() {
  Suite * s = suite_create("graph");

  TCase * tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_new_graph);

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
