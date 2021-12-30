#include "heap.h"

/**
* heap_create - creates a heap
* @data_cmp: function that determines which node is greater
*
* Return: pointer to new heap, else NULL
*/
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *out;

	if (data_cmp == NULL)
		return (NULL);

	out = malloc(sizeof(heap_t));
	if (out == NULL)
		return (NULL);

	out->size = 0;
	out->root = NULL;
	out->data_cmp = data_cmp;

	return (out);
}
