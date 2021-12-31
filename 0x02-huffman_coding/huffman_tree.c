#include "huffman.h"

/**
* huffman_tree - builds a huffman tree
* @data: array of chars
* @freq: array of frequencies, associated 1 to 1 with data
* @size: size of data and freq arrays
*
* Return: pointer to huffman tree root, else NULL
*/
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *queue;
	binary_tree_node_t *out;

	queue = huffman_priority_queue(data, freq, size);
	if (queue == NULL)
		return (NULL);

	/* doesnt specify what to do if extract_and_insert returns 0 */
	while (queue->size > 1)
		huffman_extract_and_insert(queue);

	out = heap_extract(queue);
	free(queue);
	return (out);
}
