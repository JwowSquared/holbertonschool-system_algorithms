#include "pathfinding.h"

/**
* backtracking_array - first path from starting point to target
* @map: 2D array to search through
* @rows: number of rows in map
* @cols: number of cols in map
* @start: starting point of path to find
* @target: target point of path to find
*
* Return: a queue of all points in the path starting at start
*/
queue_t *backtracking_array(char **map, int rows, int cols,
	point_t const *start, point_t const *target)
{
	queue_t *out;
	char **visited;
	int i;

	if (!map || !*map || !start || !target)
		return (NULL);

	visited = malloc(sizeof(char *) * rows);
	if (visited == NULL)
		return (NULL);

	for (i = 0; i < rows; i++)
	{
		visited[i] = calloc(cols, sizeof(char));
		if (visited[i] == NULL)
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
	}

	out = helper(map, visited, rows, cols, start->x, start->y, target);
	for (i = 0; i < rows; i++)
		free(visited[i]);
	free(visited);

	if (out == NULL)
		return (NULL);

	return (create_and_push(out, start->x, start->y));
}

queue_t *helper(char **map, char **visited, int rows, int cols,
	int x, int y, point_t const *target)
{
	queue_t *out = NULL;

	if (x < 0 || x >= cols || y < 0 || y >= rows)
		return (NULL);
	if (map[y][x] == '1' || visited[y][x])
		return (NULL);
	visited[y][x] = 1;
	printf("Checking coordinates [%d, %d]\n", x, y);

	if (target->x == x && target->y == y)
		return (queue_create());

	out = helper(map, visited, rows, cols, x + 1, y, target);
	if (out != NULL)
		return (create_and_push(out, x + 1, y));
	out = helper(map, visited, rows, cols, x, y + 1, target);
	if (out != NULL)
		return (create_and_push(out, x, y + 1));
	out = helper(map, visited, rows, cols, x - 1, y, target);
	if (out != NULL)
		return (create_and_push(out, x - 1, y));
	out = helper(map, visited, rows, cols, x, y - 1, target);
	if (out != NULL)
		return (create_and_push(out, x, y - 1));
	return (NULL);
}

/**
* create_and_push - creates a point and pushes onto the queue
* @out: queue to push onto
* @x: x coordinate of point to create
* @y: y coordinate of point to create
*
* Return: pointer to queue, else NULL
*/
queue_t *create_and_push(queue_t *out, int x, int y)
{
	point_t *tile;

	tile = malloc(sizeof(point_t));
	if (tile == NULL)
		return (NULL);

	tile->x = x;
	tile->y = y;

	if (queue_push_front(out, (void *)tile) != NULL)
		return (out);

	queue_delete(out);
	free(tile);
	return (NULL);
}

/**
* point_create - creates a point, dummy
* @x: x coordinate
* @y: y coordinate
*
* Return: pointer to new point struct, else NULL
*/
point_t *point_create(int x, int y)
{
	point_t *out;

	out = malloc(sizeof(point_t));
	if (out == NULL)
		return (NULL);

	out->x = x;
	out->y = y;

	return (out);
}
