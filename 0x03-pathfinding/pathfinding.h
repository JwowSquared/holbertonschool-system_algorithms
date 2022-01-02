#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphs.h"
#include "queues.h"

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

queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target);
queue_t *array_bt(char **, char **, int, int, int, int, point_t const *);
queue_t *create_and_push(queue_t *out, int x, int y);

queue_t *backtracking_graph(graph_t *graph,
	vertex_t const *start, vertex_t const *target);
queue_t *graph_bt(vertex_t const *, vertex_t const *, int *);

queue_t *dijkstra_graph(graph_t *graph,
	vertex_t const *start, vertex_t const *target);

#endif /* _PATHFINDING_H_ */
