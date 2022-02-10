#include "nary_trees.h"

/**
* nary_tree_traverse - visits all nodes and calls action on them
* @root: root of tree
* @action: action to call on each node
*
* Return: biggest depth reached by function
*/
size_t nary_tree_traverse(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	return (dft(root, action, 0));
}

/**
* dft - depth firts traversal of nary tree
* @node: effective root node of tree
* @action: action to call on each node
* @depth: current depth
*
* Return: biggest depth reached by function
*/
size_t dft(nary_tree_t const *node,
	void (*action)(nary_tree_t const *, size_t),
	size_t depth)
{
	nary_tree_t const *current;
	size_t temp, out = depth;

	if (node == NULL)
		return (depth);
	action(node, depth);

	current = node->children;
	while (current != NULL)
	{
		temp = dft(current, action, depth + 1);
		if (out < temp)
			out = temp;
		current = current->next;
	}
	return (out);
}
