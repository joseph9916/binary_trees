#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node must become the
 * root node.
 * If the value is already present in the tree, it must be ignored
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *present_node;

	new_node = (bst_t *)binary_tree_node(*tree, value);
	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}
	present_node = *tree;
	while (present_node)
	{
		if (value == present_node->n)
		{
			free(new_node);
			return (NULL);
		}
		else if (value > present_node->n)
		{
			if (!present_node->right)
			{
				present_node->right = new_node;
				new_node->parent = present_node;
				return (new_node);
			}
			present_node = present_node->right;
		}
		else
		{
			if (!present_node->left)
			{
				present_node->left = new_node;
				new_node->parent = present_node;
				return (new_node);
			}
			present_node = present_node->left;
		}
	}
}
