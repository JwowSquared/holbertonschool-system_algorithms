#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphs.h"
#include "queues.h"
#include "heap.h"

/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

/**
* struct djnode_s - structure storing info for dijkstra's algorithm
*
* @node: vertex this struct is referring to
* @from: immediate vertex involved in shortest path to node
* @distance: numerical value describing distance from start
*/
typedef struct djnode_s
{
	vertex_t const *node;
	struct djnode_s *from;
	int distance;
} djnode_t;

queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
queue_t *array_bt(char **, char **, int, int, int, int, point_t const *);
queue_t *create_and_push(queue_t *out, int x, int y);

queue_t *backtracking_graph(graph_t *graph,
	vertex_t const *start, vertex_t const *target);
queue_t *graph_bt(vertex_t const *, vertex_t const *, int *);

queue_t *dijkstra_graph(graph_t *graph,
	vertex_t const *start, vertex_t const *target);
queue_t *dj(vertex_t const *start, vertex_t const *target,
	djnode_t *current, int *visited, heap_t *routes);
queue_t *create_path(djnode_t *end);
void print_visit(djnode_t *current, vertex_t const *s);

djnode_t *djnode_create(vertex_t const *, djnode_t *, int);
int djnode_cmp(void *, void *);
binary_tree_node_t *find_route(binary_tree_node_t *, vertex_t *);

#endif /* _PATHFINDING_H_ */
