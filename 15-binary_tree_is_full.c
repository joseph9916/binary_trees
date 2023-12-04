#include "binary_trees.h"

/**
 * binary_tree_is_full - a function that calls binary_tree_is_full_calc
 * @tree: a pointer to the root node of the tree to check if its full.
 * Return: 1 if full or 0 if not
 * If tree is NULL, your function must return 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full;

	if (!tree)
		return (0);
	is_full = binary_tree_is_full(tree);
	return (is_full);
}


/**
 * binary_tree_is_full_calc - a function that measures the size of a
 * binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of tree or 0 if tree is NULL
 */

int binary_tree_is_full_calc(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (!tree)
		return (1);
	if (!tree->left && tree->right)
		return (0);
	if (tree->left && !tree->right)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);
	return (left_full * right_full * 1);
}
