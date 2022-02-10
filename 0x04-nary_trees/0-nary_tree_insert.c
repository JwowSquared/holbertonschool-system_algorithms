#include "nary_trees.h"

/**
* nary_tree_insert - inserts a node into an nary tree
* @parent: parent of new node to create
* @str: content of new node to create
*
* Return: pointer to new node, else NULL
*/
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *out;

	out = malloc(sizeof(nary_tree_t));
	if (out == NULL)
		return (NULL);

	/* can str be null? */
	out->content = strdup(str);
	if (out->content == NULL)
	{
		free(out);
		return (NULL);
	}

	out->parent = parent;
	out->nb_children = 0;
	out->children = NULL;
	out->next = NULL;

	if (parent != NULL)
	{
		out->next = parent->children;
		parent->children = out;
		parent->nb_children++;
	}

	return (out);
}
