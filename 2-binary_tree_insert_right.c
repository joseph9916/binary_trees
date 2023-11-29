#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node as the
 * right-child of another node
 * @parent: a pointer to the node to insert the right-child
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure or
 * if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child, *old_right_child;

	if (!parent)
		return (NULL);
	old_right_child = parent->right;
	right_child = binary_tree_node(parent, value);
	if (!right_child)
		return (NULL);
	parent->right = right_child;
	right_child->parent = parent;
	right_child->right = old_right_child;
	if (old_right_child)
		old_right_child->parent = right_child;
	return (right_child);
}
