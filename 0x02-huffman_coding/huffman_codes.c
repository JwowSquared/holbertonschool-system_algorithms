#include "huffman.h"

/**
* huffman_codes - produces the huffman codes for associated characters
* @data: array of characters
* @freq: array of frequencies
* @size: size of data and freq
*
* Return: 1 on success, else 0
*/
int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *h_tree;

	h_tree = huffman_tree(data, freq, size);
	if (h_tree == NULL)
		return (0);

	print_codes(h_tree, 0, 0);

	tree_delete(h_tree, free);

	return (1);
}

/**
* print_codes - prints the huffman codes associated with a huffman tree
* @current: current node in tree
* @code: current huffman code in decimal
* @len: current length of huffman code, for printing
*/
void print_codes(binary_tree_node_t *current, size_t code, size_t len)
{
	symbol_t *sym;

	if (current == NULL)
		return;

	sym = (symbol_t *)current->data;

	if (sym->data != -1)
	{
		printf("%c: ", sym->data);
		print_binary(code, 0, len);
		printf("\n");
	}
	print_codes(current->left, code * 2 + 0, len + 1);
	print_codes(current->right, code * 2 + 1, len + 1);
}

/**
* print_binary - displays a number in its binary form, specifically len digits
* @n: number to display
* @depth: current recursive depth
* @len: amount of digits to display
*/
void print_binary(size_t n, int depth, int len)
{
	if (depth == len)
		return;

	print_binary(n / 2, depth + 1, len);
	printf("%d", (int)n % 2);
}
