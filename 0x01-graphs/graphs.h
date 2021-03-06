#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
	vertex_t    *dest;
	struct edge_s   *next;
} edge_t;


/**
 * struct vertex_s - Node in the linked list of vertices in the adjacency list
 *
 * @index: Index of the vertex in the adjacency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of conenctions with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adjacency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
	size_t      index;
	char        *content;
	size_t      nb_edges;
	edge_t      *edges;
	struct vertex_s *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjacency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjacency linked list
 */
typedef struct graph_s
{
	size_t      nb_vertices;
	vertex_t    *vertices;
} graph_t;

/* necessary to maintain prototype and betty */
typedef graph_t g_t;
typedef vertex_t v_t;
typedef edge_type_t edge_e;

void graph_display(const graph_t *graph);

graph_t *graph_create(void);

vertex_t *graph_add_vertex(graph_t *graph, const char *str);

int graph_add_edge(graph_t *g, const char *src, const char *dest, edge_e type);
int create_edge(graph_t *graph, vertex_t *src, vertex_t *dest);

void graph_delete(graph_t *graph);

size_t depth_first_traverse(const g_t *g, void (*a)(const v_t *, size_t));
size_t dft(const v_t *c, int *v, size_t d, void (*a)(const v_t *, size_t));

size_t breadth_first_traverse(const g_t *g, void (*a)(const v_t *, size_t));
int bft(const v_t *c, int *v, int n, int d, void (*a)(const v_t *, size_t));

#endif /* _GRAPHS_H_ */
