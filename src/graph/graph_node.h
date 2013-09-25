#ifndef _KLD_GRAPH_NODE_H
#define _KLD_GRAPH_NODE_H

#include "../common/common.h"
#include "../matrix/matrix.h"
#include "graph.h"

// TODO maybe refactor out into seperate header
typedef struct kld_graph kld_graph_t;
typedef struct kld_graph_node kld_graph_node_t;

struct kld_graph_node {
   int id;
   void * data;

  // Vertices are stored as records or objects, and every vertex stores a list of adjacent vertices. 
  // This data structure allows the storage of additional data on the vertices.

  // Vertices and edges are stored as records or objects. 
  // Each vertex stores its incident edges, and each edge stores its incident vertices. 
  // This data structure allows the storage of additional data on vertices and edges.
};

/* Creates and rEturns a new <kld_graph_node>
 *
 */
kld_graph_node_t * new_graph_node(kld_graph_t * g);

#endif
