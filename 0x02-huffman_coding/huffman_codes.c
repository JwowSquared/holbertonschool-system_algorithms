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

	print_codes(h_tree, 0);

	tree_delete(h_tree, free);

	return (1);
}

/**
* print_codes - prints the huffman codes associated with a huffman tree
* @current: current node in tree
* @code: current huffman code in decimal
*/
void print_codes(binary_tree_node_t *current, size_t code)
{
	symbol_t *sym;

	if (current == NULL)
		return;

	sym = (symbol_t *)current->data;

	if (sym->data != -1)
	{
		printf("%c: ", sym->data);
		if (code != 0)
			print_binary(code);
		else
			printf("0");
		printf("\n");
	}
	print_codes(current->left, code * 2 + 0);
	print_codes(current->right, code * 2 + 1);
}

/**
* print_binary - prints a decimal number in binary
* @n: current number to print
*/
void print_binary(size_t n)
{
	if (n == 0)
		return;

	print_binary(n / 2);
	printf("%d", (int)n % 2);
}
