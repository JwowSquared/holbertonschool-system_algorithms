#include "graphs.h"

/**
* graph_add_vertex - adds a vertex to a graph
* @graph: pointer to graph struct
* @str: data to be stored in new vertex
*
* Return: pointer to new vertex, else NULL
*/
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *out, *current, *prev = NULL;
	char *data;

	if (graph == NULL)
		return (NULL);

	current = graph->vertices;
	while (current != NULL)
	{
		if (!strcmp(current->content, str))
			return (NULL);
		prev = current;
		current = current->next;
	}

	out = malloc(sizeof(vertex_t));
	if (out == NULL)
		return (NULL);
	data = strdup(str);
	if (data == NULL)
	{
		free(out);
		return (NULL);
	}

	out->content = data;
	out->next = NULL;
	out->edges = NULL;
	out->nb_edges = 0;
	out->index = 0;
	if (prev != NULL)
	{
		prev->next = out;
		out->index = prev->index + 1;
	}
	else
		graph->vertices = out;

	graph->nb_vertices += 1;
	return (out);
}
