#include <stdlib.h>
 #include "graph.h"

kld_graph_t * new_graph() {
  kld_graph_t * g = (kld_graph_t *) calloc(1, sizeof(kld_graph_t));
  g->adj_matrix = NULL;
  g->nodes = NULL;
  g->last_id = 0;
  return g;
}

bool graph_is_empty(kld_graph_t * g) {
  return g->adj_matrix == NULL && g->nodes == NULL;
}

bool graph_node_is_adjacent(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t * n2) {
  // TODO how to determine one-way adjacency
  void * data1 = matrix_get(g->adj_matrix, n1->id, n2->id);
  void * data2 =  matrix_get(g->adj_matrix, n2->id, n1->id);

  return (data1 != NULL && data2 != NULL);
}                                                                         

kld_graph_node_t * new_graph_node(kld_graph_t * g) {
  kld_graph_node_t * n = (kld_graph_node_t *) calloc(1, sizeof(kld_graph_node_t));

  if(graph_is_empty(g)) {
    g->adj_matrix = new_matrix();
    g->nodes = new_vector();
  }

  vector_append(g->nodes, n);
  n->id = g->last_id;
  g->last_id++;
  return n;
}

kld_vector_t * graph_node_neighbors(kld_graph_t * g, kld_graph_node_t * n) {
  // TODO determine how to get one-way neighbors
  kld_vector_t * res = (kld_vector_t *) new_vector();
  
  kld_vector_t * adj = g->adj_matrix->cols[n->id];
  int i;
  for(i = 0; i < adj->size; i++) {
    void * data = vector_get(adj, i);
    if(data != NULL) {
      vector_append(res, vector_get(g->nodes, i));
    }
  }

  return res;
}

void graph_insert_edge(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t * n2, void * data) {
  kld_graph_edge_t * e = new_graph_edge();
  e->data = data;
  matrix_set(g->adj_matrix, n1->id, n2->id, e);
}

kld_graph_edge_t * new_graph_edge() {
  kld_graph_edge_t * e = (kld_graph_edge_t *) calloc(1, sizeof(kld_graph_edge_t));
  e->data = NULL;
  return e;
}

void graph_remove_edge(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t * n2) {
  matrix_set(g->adj_matrix, n1->id, n2->id, NULL);
}

kld_graph_node_t * graph_get_node(kld_graph_t * g, int id) {
  return (kld_graph_node_t *) vector_get(g->nodes, id);
}

kld_graph_edge_t * graph_get_edge(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t *n2) {
  return (kld_graph_edge_t *) matrix_get(g->adj_matrix, n1->id, n2->id);
}
