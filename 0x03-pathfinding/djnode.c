#include "pathfinding.h"

/**
* djnode_create - creates a djnode
* @node: main vertex
* @from: previous node
* @d: distance
*
* Return: pointer to new djnode, else NULL
*/
djnode_t *djnode_create(vertex_t const *node, djnode_t *from, int d)
{
	djnode_t *out;

	out = malloc(sizeof(djnode_t));
	if (out == NULL)
		return (NULL);

	out->node = node;
	out->from = from;
	out->distance = d;

	return (out);
}

/**
* djnode_cmp - compares two djnodes
* @a: first node
* @b: second node
*
* Return: difference between distances
*/
int djnode_cmp(void *a, void *b)
{
	djnode_t *dj_a, *dj_b;

	dj_a = (djnode_t *)a;
	dj_b = (djnode_t *)b;

	return (dj_a->distance - dj_b->distance);
}

/**
* find_route - finds a target node within a heap
* @current: current node being checked in heap
* @target: vertex to find within the heap
*
* Return: pointer to node containing target, else NULL
*/
binary_tree_node_t *find_route(binary_tree_node_t *current, vertex_t *target)
{
	djnode_t *temp;
	binary_tree_node_t *out;

	if (!current || !target)
		return (NULL);

	temp = (djnode_t *)current->data;
	if (temp->node == target)
		return (current);

	out = find_route(current->left, target);
	if (out == NULL)
		out = find_route(current->right, target);

	return (out);
}
