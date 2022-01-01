#include "graphs.h"

/**
* breadth_first_traverse - breadth-first algorithm implementation
* @g: graph to traverse
* @a: function to call on every visited vertex
*
* Return: biggest vertex depth, else 0
*/
size_t breadth_first_traverse(const g_t *g, void (*a)(const v_t *, size_t))
{
	int *visited;
	size_t i = 0, depth = 0;
	vertex_t *start;

	if (g == NULL || a == NULL || g->vertices == NULL)
		return (0);

	visited = malloc(sizeof(int) * g->nb_vertices);
	if (visited == NULL)
		return (0);

	while (i < g->nb_vertices)
		visited[i++] = 0;

	start = g->vertices;
	while (bft(start, visited, 0, depth, a))
		depth++;

	free(visited);
	return (depth - 1);
}

/**
* bft - breadth_first_traverse but short enough to not break betty
* @c: current vertex
* @v: array keeping track of each vertex's visited status
* @n: working number to reach depth
* @d: current depth
* @a: function to use on each vertex on the first visit
*
* Return: 1 if new node visited, else 0
*/
int bft(const v_t *c, int *v, int n, int d, void (*a)(const v_t *, size_t))
{
	int found = 0;
	edge_t *current;

	if (n > d)
		return (found);

	if (n == d)
	{
		if (v[c->index] == 0)
		{
			v[c->index] = 1;
			a(c, d);
			return (1);
		}
		return (0);
	}

	current = c->edges;
	while (current != NULL)
	{
		found += bft(current->dest, v, n + 1, d, a);
		current = current->next;
	}

	return (found);
}
