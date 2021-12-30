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
	binary_tree_node_t *out, *swap;

	if (heap == NULL || heap->root == NULL)
		return (NULL);

	data = heap->root->data;
	out = heap->root;
	while (out->left != NULL)
	{
		swap = out->left;
		if (out->right != NULL && heap->data_cmp(swap->data, out->right->data) > 0)
			swap = out->right;
		temp = out->data;
		out->data = swap->data;
		swap->data = temp;
		out = swap;
	}
	swap = find_parent(heap, heap->size, heap->size);
	if (swap == NULL)
		swap = heap->root;
	else if (heap->size % 2 == 0)
	{
		swap = swap->left;
		swap->parent->left = NULL;
	}
	else
	{
		swap = swap->right;
		swap->parent->right = NULL;
	}
	out->data = swap->data;
	free(swap);
	heap->size = heap->size - 1;
	if (heap->size == 0)
		heap->root = NULL;
	return (data);
}
