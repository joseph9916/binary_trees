#include "binary_trees.h"

/**
 * max - finds maximum height and returns it
 * @first: first height
 * @second: second height
 * Return: maximum height
 */
size_t max(size_t first, size_t second)
{
	if (second > first)
		return (second);
	return (first);
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
	return (max(left_height, right_height) + 1);
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
