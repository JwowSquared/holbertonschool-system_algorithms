#include "graphs.h"

/**
* graph_delete - frees all memory associated with a graph
* @graph: pointer to graph to delete
*/
void graph_delete(graph_t *graph)
{
	vertex_t *v_current, *v_prev;
	edge_t *e_current, *e_prev;

	if (graph == NULL)
		return;

	v_current = graph->vertices;
	while (v_current != NULL)
	{
		e_current = v_current->edges;
		while (e_current != NULL)
		{
			e_prev = e_current;
			e_current = e_current->next;
			free(e_prev);
		}
		v_prev = v_current;
		v_current = v_current->next;
		free(v_prev->content);
		free(v_prev);
	}
	free(graph);
}
