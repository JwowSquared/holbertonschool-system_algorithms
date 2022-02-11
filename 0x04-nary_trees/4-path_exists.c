#include "nary_trees.h"

/**
* path_exists - checks if a path exists in a file system
* @root: root of nary tree to check through
* @path: path to check existence of
*
* Return: 1 on success, else 0
*/
int path_exists(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t *current;
	int i;

	if (root == NULL || path == NULL || *path == NULL)
		return (0);

	if (strcmp(root->content, path[0]))
		return (0);

	i = 1;
	current = root->children;
	while (current != NULL && path[i] != NULL)
	{
		if (!strcmp(current->content, path[i]))
		{
			i++;
			current = current->children;
		}
		else
			current = current->next;
	}

	if (path[i] == NULL)
		return (1);
	return (0);
}
