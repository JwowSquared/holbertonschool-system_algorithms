#include "heap.h"

/**
* heap_extract - extracts the root of the heap and rebuilds it
* @heap: heap to extract from
*
* Return: pointer to data of extracted node, else NULL
*/
void *heap_extract(heap_t *heap)
{
	void *data, *temp;
	binary_tree_node_t *out, *swap, *last;

	if (heap == NULL || heap->root == NULL)
		return (NULL);

	data = heap->root->data;
	out = heap->root;
	last = find_parent(heap, heap->size, heap->size);
	if (last == NULL)
		last = heap->root;
	else if (heap->size % 2 == 0)
	{
		last = last->left;
		last->parent->left = NULL;
	}
	else
	{
		last = last->right;
		last->parent->right = NULL;
	}
	out->data = last->data;

	while (out->left != NULL)
	{
		swap = out->left;
		if (out->right != NULL && heap->data_cmp(swap->data, out->right->data) > 0)
			swap = out->right;
		if (heap->data_cmp(out->data, swap->data) < 0)
			break;
		temp = out->data;
		out->data = swap->data;
		swap->data = temp;
		out = swap;
	}
	free(last);
	heap->size = heap->size - 1;
	if (heap->size == 0)
		heap->root = NULL;
	return (data);
}
