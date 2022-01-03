#include "pathfinding.h"

/**
* dijkstra_graph - determines the shortest route to target
* @graph: graph to peruse
* @start: start of path
* @target: end of path
*
* Return: queue representing the shortest path, else NULL
*/
queue_t *dijkstra_graph(graph_t *graph,
	vertex_t const *start, vertex_t const *target)
{
	queue_t *out;
	heap_t *routes;
	djnode_t *dj_start;
	int *visited;

	if (!graph || !start || !target)
		return (NULL);

	visited = calloc(graph->nb_vertices, sizeof(int));
	if (visited == NULL)
		return (NULL);

	dj_start = djnode_create(start, NULL, 0);
	if (dj_start == NULL)
	{
		free(visited);
		return (NULL);
	}

	routes = heap_create(djnode_cmp);
	if (routes == NULL)
	{
		free(visited);
		free(dj_start);
		return (NULL);
	}

	out = dj(start, target, dj_start, visited, routes);
	free(visited);
	free(dj_start);
	heap_delete(routes, NULL);
	return (out);
}

/**
* dj - implementation of dijkstra's algorithm
* @start: vertex that begins the path
* @target: vertex we want to find
* @current: djnode repesenting current vertex to check
* @visited: array holding visitation status of all vertices
* @routes: priority queue of all potential routes
*
* Return: path represented by queue, else NULL
*/
queue_t *dj(vertex_t const *start, vertex_t const *target,
	djnode_t *current, int *visited, heap_t *routes)
{
	queue_t *out;
	edge_t *e_current;
	djnode_t *route;
	binary_tree_node_t *route_node;
	int new_distance;

	visited[current->node->index] = 1;
	print_visit(current, start);

	if (current->node == target)
		return (create_path(current));

	e_current = current->node->edges;
	for (; e_current != NULL; e_current = e_current->next)
	{
		if (visited[e_current->dest->index])
			continue;
		new_distance = current->distance + e_current->weight;
		route_node = find_route(routes->root, e_current->dest);
		if (route_node == NULL)
		{
			route = djnode_create(e_current->dest, current, new_distance);
			if (route == NULL)
				return (NULL);
			heap_insert(routes, (void *)route);
		}
		else
			route = (djnode_t *)route_node->data;
		if (route->distance > new_distance)
		{
			route->distance = new_distance;
			swap_up(routes, route_node);
		}
	}
	route = heap_extract(routes);
	if (route == NULL)
		return (NULL);
	out = dj(start, target, route, visited, routes);
	free(route);
	return (out);
}

/**
* create_path - turns a series of djnodes into a queue
* @end: end of path to follow backwards
*
* Return: pointer to path queue, else NULL
*/
queue_t *create_path(djnode_t *end)
{
	queue_t *out;
	djnode_t *current;
	char *city;

	out = queue_create();
	if (out == NULL)
		return (NULL);

	current = end;
	while (current != NULL)
	{
		city = strdup(current->node->content);
		if (city == NULL)
		{
			queue_delete(out);
			return (NULL);
		}
		if (queue_push_front(out, (void *)city) == NULL)
		{
			queue_delete(out);
			return (NULL);
		}
		current = current->from;
	}

	return (out);
}

/**
* print_visit - prints when visiting a new city
* @current: current city
* @s: reference to starting city
*/
void print_visit(djnode_t *current, vertex_t const *s)
{
	char *city, *start, *prompt;
	int distance;

	city = current->node->content;
	start = s->content;
	distance = current->distance;
	prompt = "Checking %s, distance from %s is %d\n";

	printf(prompt, city, start, distance);
}
