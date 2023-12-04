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

/**
 * binary_sub_tree_height - a function that measures the height of a
 * binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height of tree
 * If tree is NULL, your function must return 0
 */

size_t binary_sub_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	left_height = binary_sub_tree_height(tree->left);
	right_height = binary_sub_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * binary_tree_balance -  function that measures the balance factor
 * of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of tree
 * If tree is NULL, your function must return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);
	left_height = binary_sub_tree_height(tree->left);
	right_height = binary_sub_tree_height(tree->right);
	return (left_height - right_height);
}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: if perfect else return 0
 * If tree is NULL, your function must return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (binary_tree_is_full(tree))
		if (!binary_tree_balance(tree))
			return (1);
	return (0);
}
