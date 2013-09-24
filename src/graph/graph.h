#ifndef _KLD_GRAPH_H
#define _KLD_GRAPH_H

#include "../common/common.h"
#include "../matrix/matrix.h"

typedef struct kld_graph kld_graph_t;
typedef struct kld_graph_node kld_graph_node_t;
typedef struct kld_graph_edge kld_graph_edge_t;

struct kld_graph {
  kld_matrix_t * adj_matrix;
};

kld_graph_t * new_graph();
bool graph_is_empty(kld_graph_t * g);

bool graph_node_is_adjacent(kld_graph_t *g, int x, int y);
kld_vector_t * graph_node_neighbors(kld_graph_t * g, int x);
void graph_insert_edge(kld_graph_t * g, int x, int y, void * data);
void graph_remove_edge(kld_graph_t * g, int x, int y);
kld_graph_node_t * graph_get_node(kld_graph_t * g, int x);
kld_graph_node_t * graph_set_node(kld_graph_t * g, int x, void * data);

//Structures that associate values to the edges usually also provide:
kld_graph_edge_t * graph_get_edge(kld_graph_t * g, kld_graph_node_t * x, kld_graph_node_t * y); //: returns the value associated to the edge (x,y).
void graph_set_edge(kld_graph_t * g, int x, int y, void * data); //sets the value associated to the edge (x,y) to v.
     
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
