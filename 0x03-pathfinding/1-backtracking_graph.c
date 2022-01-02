#include "pathfinding.h"

/**
* backtracking_graph - finds a path from start to target
* @graph: data structure to look through
* @start: start of path
* @target: end of path
*
* Return: queue of vertices that describe the path found
*/
queue_t *backtracking_graph(graph_t *graph,
	vertex_t const *start, vertex_t const *target)
{
	queue_t *out;
	int *visited;

	if (!graph || !start || !target)
		return (NULL);

	visited = calloc(graph->nb_vertices, sizeof(int));
	if (visited == NULL)
		return (NULL);

	out = graph_bt(start, target, visited);
	free(visited);
	if (out == NULL)
		return (NULL);

	if (queue_push_front(out, (void *)start->content) == NULL)
	{
		queue_delete(out);
		return (NULL);
	}

	return (out);
}

/**
* graph_bt - finds path in graph by backtracking
* @v_current: current vertex
* @target: target vertex
* @visited: array of visitation status for all vertices
*
* Return: pointer to queue that holds path, else NULL
*/
queue_t *graph_bt(vertex_t const *v_current,
	vertex_t const *target, int *visited)
{
	queue_t *out;
	edge_t *e_current;
	char *city;

	if (visited[v_current->index])
		return (NULL);
	visited[v_current->index] = 1;
	printf("Checking %s\n", v_current->content);

	if (v_current == target)
		return (queue_create());

	e_current = v_current->edges;
	while (e_current != NULL)
	{
		out = graph_bt(e_current->dest, target, visited);
		if (out != NULL)
		{
			city = e_current->dest->content;
			if (queue_push_front(out, (void *)city) == NULL)
			{
				queue_delete(out);
				return (NULL);
			}
			return (out);
		}
		e_current = e_current->next;
	}
	return (NULL);
}
