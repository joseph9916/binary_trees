#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 * If a value of the array is already present in the tree, this value must
 * be ignored
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *tree;

	if (!array)
		return (NULL);
	tree = NULL;
	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
