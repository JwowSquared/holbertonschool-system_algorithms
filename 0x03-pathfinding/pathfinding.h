#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdio.h>
#include <stdlib.h>

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

typedef queue_t q_t;
typedef point_t p_t;

queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);
queue_t *helper(char **, char **, int, int, int, int, int, int, point_t const *);
point_t *point_create(int, int);

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);

#endif /* _PATHFINDING_H_ */
