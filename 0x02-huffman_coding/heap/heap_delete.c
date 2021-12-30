#include "heap.h"

/**
* heap_delete - deletes a heap
* @heap: pointer to heap to delete
* @free_data: function that frees data stored in the heap nodes data member
*/
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap == NULL)
		return;

	tree_delete(heap->root, free_data);
	free(heap);
}

/**
* tree_delete - deletes a binary tree
* @current: current node to delete
* @free_data: function used to free current->data, or NULL
*/
void tree_delete(binary_tree_node_t *current, void (*free_data)(void *))
{
	binary_tree_node_t *left, *right;

	if (current == NULL)
		return;

	left = current->left;
	right = current->right;

	if (free_data != NULL)
		free_data(current->data);
	free(current);

	tree_delete(left, free_data);
	tree_delete(right, free_data);
}
