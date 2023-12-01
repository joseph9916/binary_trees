#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that measures the leaves of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: leaves of tree or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves, right_leaves;

	if (!tree)
		return (0);
	left_leaves = binary_tree_leaves(tree->left);
	right_leaves = binary_tree_leaves(tree->right);
	if (tree->left || tree->right)
		return (left_leaves + right_leaves + 0);
	return (left_leaves + right_leaves + 1);
}
