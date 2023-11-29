#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the
 * left-child of another node
 * @parent: a pointer to the node to insert the left-child
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure or
 * if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child, *old_left_child;

	if (!parent)
		return (NULL);
	old_left_child = parent->left;
	left_child = binary_tree_node(parent, value);
	if (!left_child)
		return (NULL);
	parent->left = left_child;
	left_child->parent = parent;
	left_child->left = old_left_child;
	if (old_left_child)
		old_left_child->parent = left_child;
	return (left_child);
}
