#include "heap.h"

/**
* binary_tree_node - creates a new binary tree node
* @parent: parent of new node
* @data: data to be stored in the new node
*
* Return: pointer to new node, else NULL
*/
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *out;

	out = malloc(sizeof(binary_tree_node_t));
	if (out == NULL)
		return (NULL);

	out->data = data;
	out->parent = parent;
	out->left = NULL;
	out->right = NULL;

	return (out);
}
