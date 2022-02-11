#include "nary_trees.h"

/**
* nary_tree_diameter - determines the diameter of an nary tree
* @root: root of tree
*
* Return: diameter of tree
*/
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t out = 0, temp;

	temp = nt_diameter(root, &out);
	if (out < temp)
		out = temp;
	return (out);
}

/**
* nt_diameter - determines the diameter of an nary tree
* @node: current effective root of tree
* @out: current max diameter that has been found
*
* Return: diameter of tree
*/
size_t nt_diameter(nary_tree_t const *node, size_t *out)
{
	nary_tree_t const *current;
	size_t temp, first = 0, second = 0;

	if (node == NULL)
		return (0);

	/* find 2 tallest children */
	current = node->children;
	while (current != NULL)
	{
		temp = nt_diameter(current, out);
		if (first < temp)
		{
			second = first;
			first = temp;
		}
		else if (second < temp)
			second = temp;
		current = current->next;
	}

	/* overwrite current max diameter with local diameter if applicable */
	temp = first + second + 1;
	if (*out < temp)
		*out = temp;

	/* return height */
	temp = first;
	if (first < second)
		temp = second;
	return (temp + 1);
}
