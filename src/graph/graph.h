#ifndef _KLD_GRAPH_H
#define _KLD_GRAPH_H

#include "../common/common.h"

typedef struct kld_graph kld_graph_t;
typedef struct kld_graph_node kld_graph_node_t;
typedef struct kld_graph_edge kld_graph_edge_t;

struct kld_graph {
  // TODO implement
  // TODO Implement vectors such that we can use them for a matrix implementaiton

  // Adjacency Matrix
  // Incidence Matrix
};

struct kld_graph_node {
  int id;
  void * data;

  // Vertices are stored as records or objects, and every vertex stores a list of adjacent vertices. 
  // This data structure allows the storage of additional data on the vertices.

  // Vertices and edges are stored as records or objects. 
  // Each vertex stores its incident edges, and each edge stores its incident vertices. 
  // This data structure allows the storage of additional data on vertices and edges.
};

struct kld_graph_edge {
  void * data;

  // Vertices and edges are stored as records or objects. 
  // Each vertex stores its incident edges, and each edge stores its incident vertices. 
  // This data structure allows the storage of additional data on vertices and edges.
};

#endif
