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
	point_t *tile;

	if (!map || !*map || !start || !target)
		return (NULL);

	out = helper(map, rows, cols, -1, -1, start->x, start->y, target);
	if (out == NULL)
		return (NULL);

	tile = point_create(start->x, start->y);
	if (tile == NULL)
	{
		queue_delete(out);
		return (NULL);
	}

	if (queue_push_front(out, (void *)tile) == NULL)
	{
		free(tile);
		queue_delete(out);
		return (NULL);
	}

	return (out);
}

queue_t *helper(char **map, int rows, int cols, int px, int py,
	int x, int y, point_t const *target)
{
	queue_t *out = NULL;
	point_t *tile = NULL;

	printf("Checking coordinates [%d, %d]\n", x, y);

	if (target->x == x && target->y == y)
		return (queue_create());

	if (x < cols - 1 && map[y][x + 1] == '0' && x + 1 != px)
	{
		out = helper(map, rows, cols, x, y, x + 1, y, target);
		if (out != NULL)
			tile = point_create(x + 1, y);
	}
	if (out == NULL && y > 0 && map[y - 1][x] == '0' && y - 1 != py)
	{
		out = helper(map, rows, cols, x, y, x, y - 1, target);
		if (out != NULL)
			tile = point_create(x, y - 1);
	}
	if (out == NULL && x > 0 && map[y][x - 1] == '0' && x - 1 != px)
	{
		out = helper(map, rows, cols, x, y, x - 1, y, target);
		if (out != NULL)
			tile = point_create(x - 1, y);
	}
	if (out == NULL && y < rows - 1 && map[y + 1][x] == '0' && y + 1 != py)
	{
		out = helper(map, rows, cols, x, y, x, y + 1, target);
		if (out != NULL)
			tile = point_create(x, y + 1);
	}

	if (tile != NULL)
	{
		if (queue_push_front(out, (void *)tile) == NULL)
		{
			queue_delete(out);
			free(tile);
			return (NULL);
		}
		return (out);
	}

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
