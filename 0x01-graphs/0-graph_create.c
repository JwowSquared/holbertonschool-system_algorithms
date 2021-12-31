#include "graphs.h"

/**
* graph_create - creates a graph
*
* Return: pointer to empty graph struct, else NULL
*/
graph_t *graph_create(void)
{
	graph_t *out;

	out = malloc(sizeof(graph_t));
	if (out == NULL)
		return (NULL);

	out->nb_vertices = 0;
	out->vertices = NULL;

	return (out);
}
