#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that measures the nodes of a binary tree
 * @tree: a pointer to the root node of the tree to measure the nodes
 * Return: nodes of tree or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_node, right_node;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left_node = binary_tree_nodes(tree->left);
	right_node = binary_tree_nodes(tree->right);
	return (left_node + right_node + 1);
}
