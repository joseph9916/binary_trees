#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs a right-rotation
 * on a binary tree
 * @tree: tree is a pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_right_child, *left_child;
	binary_tree_t *grand_parent;

	if (!tree)
		return (NULL);
	left_child = tree->left;
	grand_parent = tree->parent;
	if (!left_child)
		return (NULL);
	left_right_child = left_child->right;
	if (grand_parent)
	{
		if (tree == grand_parent->left)
			grand_parent->left = left_child;
		else
			grand_parent->right = left_child;
	}
	tree->parent = left_child;
	left_child->parent = grand_parent;
	left_child->right = tree;
	tree->left = left_right_child;
	return (left_child);
}
