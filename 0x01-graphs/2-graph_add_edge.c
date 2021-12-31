#include "graphs.h"

/**
* graph_add_edge - creates an edge within a graph
* @g: pointer to graph struct
* @src: string representing source vertex
* @dest: string representing destination vertex
* @type: determines whether the edge goes both ways or only one way
*
* Return: 1 on success, else 0
*/
int graph_add_edge(graph_t *g, const char *src, const char *dest, edge_e type)
{
	vertex_t *current, *v_src = NULL, *v_dest = NULL;

	if (g == NULL || src == NULL || dest == NULL)
		return (0);

	current = g->vertices;
	while (current != NULL)
	{
		if (v_src == NULL && !strcmp(current->content, src))
			v_src = current;
		if (v_dest == NULL && !strcmp(current->content, dest))
			v_dest = current;
		if (v_src != NULL && v_dest != NULL)
			break;
		current = current->next;
	}

	if (!create_edge(g, v_src, v_dest))
		return (0);
	if (type == BIDIRECTIONAL)
		if (!create_edge(g, v_dest, v_src))
			return (0);

	return (1);
}

/**
* create_edge - creates an edge from src to dest in graph
* @graph: pointer to graph struct
* @src: source vertex
* @dest: destination vertex
*
* Return: 1 on success, else 0
*/
int create_edge(graph_t *graph, vertex_t *src, vertex_t *dest)
{
	edge_t *out, *current;

	if (graph == NULL || src == NULL || dest == NULL)
		return (0);

	current = src->edges;
	if (current != NULL) /* maybe check for duplicate dest? */
		while (current->next != NULL)
			current = current->next;

	out = malloc(sizeof(edge_t));
	if (out == NULL)
		return (0);

	out->dest = dest;
	out->next = NULL;
	if (current == NULL)
		src->edges = out;
	else
		current->next = out;

	src->nb_edges += 1;
	return (1);
}
