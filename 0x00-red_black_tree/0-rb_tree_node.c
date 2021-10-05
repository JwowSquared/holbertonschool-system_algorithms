#include "rb_trees.h"

/**
* rb_tree_node - creates new red black tree node
* @parent: parent node of new node
* @value: value to be stored in new node
* @color: color of new node
*
* Return: address of new node, else NULL
*/
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *out;

	out = malloc(sizeof(rb_tree_t));
	if (out == NULL)
		return (NULL);

	out->parent = parent;
	out->n = value;
	out->color = color;
	out->left = NULL;
	out->right = NULL;

	return (out);
}
