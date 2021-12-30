#include "huffman.h"

/**
* huffman_priority_queue - creates a huffman priority queue
* @data: array of data to add
* @freq: array of freq to add
* @size: size of data and freq arrays
*
* Return: pointer to new heap, else NULL
*/
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	size_t i = 0;
	symbol_t *sym;
	binary_tree_node_t *node;
	heap_t *out;

	out = heap_create(leaf_symbol_cmp);
	if (out == NULL)
		return (NULL);

	while (i < size)
	{
		sym = symbol_create(data[i], freq[i]);
		if (sym == NULL)
		{
			heap_delete(out, free);
			return (NULL);
		}
		node = binary_tree_node(NULL, (void *)sym);
		if (node == NULL)
		{
			free(sym);
			heap_delete(out, free);
			return (NULL);
		}
		heap_insert(out, (void *)node);
		i++;
	}

	return (out);
}

/**
* leaf_symbol_cmp - compares two symbols that are leaves of independent trees
* @node_a: node a
* @node_b: node b
*
* Return: difference between a and b's leaf freq value
*/
int leaf_symbol_cmp(void *node_a, void *node_b)
{
	binary_tree_node_t *n_a, *n_b;
	symbol_t *a, *b;

	n_a = (binary_tree_node_t *)node_a;
	n_b = (binary_tree_node_t *)node_b;

	a = (symbol_t *)n_a->data;
	b = (symbol_t *)n_b->data;

	return (a->freq - b->freq);
}
