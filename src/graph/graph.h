#ifndef _KLD_GRAPH_H
#define _KLD_GRAPH_H

#include "../common/common.h"
#include "../matrix/matrix.h"
#include "graph_node.h"

typedef struct kld_graph kld_graph_t;
typedef struct kld_graph_edge kld_graph_edge_t;

struct kld_graph {
  kld_matrix_t * adj_matrix;
  kld_vector_t * nodes;
  int last_id;
};

/* Creates and returns a pointer to a new <kld_graph_t>
 *
 * @return a pointer to a new <kld_graph_t>
 */
kld_graph_t * new_graph();

/* Returns whether or not a graph is empty
 * @g the <kld_graph_t> in which to test for emptiness
 *
 * @return true if the graph is empty and false if otherwise
 */
bool graph_is_empty(kld_graph_t * g);

/* Returns whether or not the passed in <kld_graph_node_t> **n1** is adjacent to the passed in <kld_graph_node_t> **n2**
 * @g the <kld_graph_t> in which to test for adjacency
 * @n1 the <kld_graph_node_t> in which to test is adjacent to <kld_graph_node_t> **n2**
 * @n2 the <kld_graph_node_t> in which to test is adjacent to <kld_graph_node_t> **n1**
 *
 * @return true if **n1** is adjacent to **n2** and false if otherwise
 */
bool graph_node_is_adjacent(kld_graph_t *g, kld_graph_node_t * n1, kld_graph_node_t * n2);

/* Returns a <kld_vector_t> of all the current neighbors of <kld_graph_node_t> **n** inside of <kld_graph_t> **g**.
 * @g the <kld_graph_t> in which to retrieve neighbors.
 * @n the <kld_graph_node_t> in which to retrieve neighbors.
 *
 * @return a <kld_vector_t> of all the current neighbors of <kld_graph_node_t> **n** inside of <kld_graph_t> **g**.
 */
kld_vector_t * graph_node_neighbors(kld_graph_t * g, kld_graph_node_t * n);

/* Inserts the passed int **data** as a <kld_graph_edge_t> into the <kld_graph_t> **g**
 * @g the <kld_graph_t> in which to insert the **data**
 * @n1 the source <kld_graph_node_t> in which to insert the edge
 * @n2 the destination <kld_graph_node_t> in which to insert the edge
 * @data the data to be stored at the new <kld_graph_edge_t>
 */
void graph_insert_edge(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t * n2, void * data);

/* Removes a <kld_graph_edge_t> from the <kld_graph_t> **g** that connects **n1** to **n2**.
 * @g the <kld_graph_t> in which to remove the <kld_graph_edge_t>
 * @n1 the source <kld_graph_node_t> in which to remove the edge
 * @n2 the destination <kld_graph_node_t> in which to remove the edge
 */
void graph_remove_edge(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t * n2);

kld_graph_node_t * graph_get_node(kld_graph_t * g, int x);
void  graph_node_set_data(kld_graph_node_t * n, void * data);
kld_graph_edge_t * graph_get_edge(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t * n2); 
void graph_edge_set_data(kld_graph_edge_t * e, void * data); 
     
struct kld_graph_edge {
  void * data;

  // Vertices and edges are stored as records or objects. 
  // Each vertex stores its incident edges, and each edge stores its incident vertices. 
  // This data structure allows the storage of additional data on vertices and edges.
};

kld_graph_edge_t * new_graph_edge();

#endif
