#ifndef _KLD_GRAPH_H
#define _KLD_GRAPH_H

#include "../common/common.h"
#include "../matrix/matrix.h"

typedef struct kld_graph kld_graph_t;

// TODO Seperate these out into seperate headers and implementation files
typedef struct kld_graph_node kld_graph_node_t;
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

/* Returns the <kld_graph_node_t> of the passed in **id**.
 * @g the <kld_graph_t> in which to retrieve the <kld_graph_node_t>
 * @id the id of the desired <kld_graph_node_t>
 *
 * @return the <kld_graph_node_t> stored in the <kld_graph_t> **g** with the specified **id**.
 */
kld_graph_node_t * graph_get_node(kld_graph_t * g, int id);

/* Returns the <kld_graph_edge_t> that spans between a source <kld_graph_node_t> **n1**, and arrives at a desitination <kld_graph_node_t> **n2**.
 * @g the <kld_graph_node_t> in which to retrieve the edge
 * @n1 the source <kld_graph_node_t> in which to retrieve the edge
 * @n1 the destination <kld_graph_node_t> in which to retrieve the edge
 *
 * @return the <kld_graph_edge_t> that spans between **n1** and **n2**.
 */
kld_graph_edge_t * graph_get_edge(kld_graph_t * g, kld_graph_node_t * n1, kld_graph_node_t * n2); 

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

     
struct kld_graph_edge {
  void * data;

  // Vertices and edges are stored as records or objects. 
  // Each vertex stores its incident edges, and each edge stores its incident vertices. 
  // This data structure allows the storage of additional data on vertices and edges.
};

kld_graph_edge_t * new_graph_edge();

#endif
