#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found, your function must return NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree)
	{
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
		else
			return ((bst_t *)tree);
	}
	return ((bst_t *)tree);
}
