#include "huffman.c"

/**
* symbol_create - creates a symbol for use in a Huffman tree
* @data: data to store in symbol
* @freq: technically also data to store in symbol
*
* Return: pointer to new symbol, else NULL
*/
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *out;

	out = malloc(sizeof(symbol_t));
	if (out == NULL)
		return (NULL);

	out->data = data;
	out->freq = freq;

	return (out);
}
