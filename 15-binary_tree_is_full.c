#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_full_calc - a function that measures the size of a
 * binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of tree or 0 if tree is NULL
 */

int binary_tree_is_full_calc(const binary_tree_t *tree)
{
	int left_full = 1, right_full = 1;

	if (!tree)
		return (1);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
	{
		left_full = binary_tree_is_full_calc(tree->left);
		right_full = binary_tree_is_full_calc(tree->right);
		return (left_full * right_full * 1);
	}
	return (0);
}

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
	is_full = binary_tree_is_full_calc(tree);
	return (is_full);
}
