#include "rb_trees.h"

int helper(int n, const rb_tree_t *tree);

/**
* rb_tree_is_valid - tests a red black tree
* @tree: pointer to red black tree to verify
*
* Return: 1 if tree is a valid red-black tree, else 0
*/
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->color != BLACK)
		return (0);

	if (helper(0, tree) == -1)
		return (0);

	return (1);
}

/**
* helper - recursively checks validity of red black tree
* @n: current black height of tree
* @tree: current node
*
* Return: -1 on failure, else black height of tree
*/
int helper(int n, const rb_tree_t *tree)
{
	int out;

	if (tree == NULL)
		return (n);

	if (tree->color != BLACK && tree->color != RED)
		return (-1);

	if (tree->color == RED && tree->parent->color == RED)
		return (-1);

	if (tree->color == BLACK)
		n++;

	out = helper(n, tree->left);
	if (out != helper(n, tree->right))
		return (-1);

	return (out);
}
