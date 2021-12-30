#include "heap.h"

/**
* heap_insert - inserts a new node into the heap
* @heap: pointer to heap
* @data: data to be stored in the new node
*
* Return: pointer to new node, else NULL
*/
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	size_t dest;
	binary_tree_node_t *out;

	if (heap == NULL || data == NULL)
		return (NULL);

	dest = heap->size + 1;
	out = binary_tree_node(find_parent(heap, dest, dest), data);
	if (out == NULL)
		return (NULL);
	if (out->parent != NULL)
	{
		if (out->parent->left != NULL)
			out->parent->right = out;
		else
			out->parent->left = out;
	}

	out = swap_up(heap, out);

	heap->size = dest;

	return (out);
}

/**
* find_parent - returns the parent of the new node to add
* @heap: pointer to heap
* @idx: working value to determing the left/right moves to reach dest
* @dest: destination index of new node
*
* Return: pointer to parent of new node, else NULL
*/
binary_tree_node_t *find_parent(heap_t *heap, size_t idx, size_t dest)
{
	binary_tree_node_t *current;

	if (idx == 1)
		return (heap->root);

	current = find_parent(heap, idx / 2, dest);

	if (idx == dest)
		return (current);

	if (idx % 2 == 0)
		return (current->left);
	return (current->right);
}

/**
* swap_up - swaps out up the tree until the tree is balanced
* @heap: pointer to heap
* @out: node that was just added to the tree
*
* Return: pointer to the node that holds the new data
*/
binary_tree_node_t *swap_up(heap_t *heap, binary_tree_node_t *out)
{
	void *temp;

	while (out->parent != NULL)
	{
		if (heap->data_cmp(out->data, out->parent->data) > 0)
			break;
		temp = out->data;
		out->data = out->parent->data;
		out->parent->data = temp;
		out = out->parent;
	}

	if (out->parent == NULL)
		heap->root = out;

	return (out);
}
