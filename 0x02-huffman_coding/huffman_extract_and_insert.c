#include "huffman.h"

/**
* huffman_extract_and_insert - extracts 2 nodes and re-adds them combined
* @priority_queue: heap to extract from
*
* Return: 1 on success, else 0
*/
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *left, *right, *out;
	symbol_t *sym;
	size_t total_freq;

	if (priority_queue->size <= 1)
		return (0);

	left = heap_extract(priority_queue);
	right = heap_extract(priority_queue);
	total_freq = ((symbol_t *)left->data)->freq;
	if (right != NULL)
		total_freq += ((symbol_t *)right->data)->freq;

	sym = symbol_create(-1, total_freq);
	if (sym == NULL)
		return (0);

	out = binary_tree_node(NULL, (void *)sym);
	if (out == NULL)
	{
		free(sym);
		return (0);
	}

	out->left = left;
	out->right = right;
	left->parent = out;
	if (right != NULL)
		right->parent = out;

	heap_insert(priority_queue, (void *)out);
	return (1);
}
