#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs a left-rotation
 * on a binary tree
 * @tree: tree is a pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_left_child, *right_child;
	binary_tree_t *grand_parent;

	if (!tree)
		return (NULL);
	right_child = tree->right;
	grand_parent = tree->parent;
	if (!right_child)
		return (NULL);
	right_left_child = right_child->left;
	if (grand_parent)
	{
		if (tree == grand_parent->left)
			grand_parent->left = right_child;
		else
			grand_parent->right = right_child;
	}
	tree->parent = right_child;
	right_child->parent = grand_parent;
	right_child->left = tree;
	tree->right = right_left_child;
	return (right_child);
}
