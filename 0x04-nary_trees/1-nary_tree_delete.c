#include "nary_trees.h"

/**
* nary_tree_delete - deletes an entire nary tree
* @tree: tree to delete
*/
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *current, *prev;

	if (tree == NULL)
		return;

	current = tree->children;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		nary_tree_delete(prev);
	}
	free(tree->content);
	free(tree);
}
