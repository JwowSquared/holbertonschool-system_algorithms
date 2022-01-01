#include "graphs.h"

/**
* depth_first_traverse - depth-first algorithm implementation
* @g: graph to traverse
* @a: function to call on every visited vertex
*
* Return: biggest vertex depth, else 0
*/
size_t depth_first_traverse(const g_t *g, void (*a)(const v_t *, size_t))
{
	int *visited;
	size_t i = 0;

	if (g == NULL || a == NULL || g->vertices == NULL)
		return (0);

	visited = malloc(sizeof(int) * g->nb_vertices);
	if (visited == NULL)
		return (0);

	while (i < g->nb_vertices)
		visited[i++] = 0;

	i = dft(g->vertices, visited, 0, a);

	free(visited);
	return (i);
}

/**
* dft - depth_first_traverse but short enough to allow variable names
* @c: current vertex
* @v: array keeping track of each vertex's visited status
* @d: current depth
* @a: function to use on each vertex on the first visit
*
* Return: biggest vertex depth, else 0
*/
size_t dft(const v_t *c, int *v, size_t d, void (*a)(const v_t *, size_t))
{
	edge_t *current;
	size_t max, temp;

	max = d;

	if (v[c->index] == 0)
	{
		a(c, d);
		v[c->index] = 1;
	}

	current = c->edges;
	while (current != NULL)
	{
		if (v[current->dest->index] == 0)
		{
			temp = dft(current->dest, v, d + 1, a);
			if (max < temp)
				max = temp;
		}
		current = current->next;
	}

	return (max);
}
