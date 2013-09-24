#include <stdlib.h>
#include "graph.h"

kld_graph_t * new_graph() {
  kld_graph_t * g = (kld_graph_t *) calloc(1, sizeof(kld_graph_t));
  g->adj_matrix = NULL;
  return g;
}
                                                                         
