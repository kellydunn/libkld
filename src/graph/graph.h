#ifndef _KLD_GRAPH_H
#define _KLD_GRAPH_H

#include "../list/list.h"

typedef struct kld_graph kld_graph_t;
typedef struct kld_graph_node kld_graph_node_t;
typedef struct kld_graph_edge kld_graph_edge_t;

struct kld_graph {
  // TODO implement
  // Adjacency Matrix
  // Incidence Matrix
};

struct kld_graph_node {
  void * data;

  // Vertices are stored as records or objects, and every vertex stores a list of adjacent vertices. 
  // This data structure allows the storage of additional data on the vertices.
  kld_list_t * adjacent_nodes;

  // Vertices and edges are stored as records or objects. 
  // Each vertex stores its incident edges, and each edge stores its incident vertices. 
  // This data structure allows the storage of additional data on vertices and edges.
  kld_list_t * incident_edges;
};

struct kld_graph_edge {
  void * data;

  // Vertices and edges are stored as records or objects. 
  // Each vertex stores its incident edges, and each edge stores its incident vertices. 
  // This data structure allows the storage of additional data on vertices and edges.
  kld_list_t * incident_nodes;
};

#endif
