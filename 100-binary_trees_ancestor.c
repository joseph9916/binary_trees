#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds the
 * lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * if no common ancestor was found, your function must return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, 
					const binary_tree_t *second)
{
	const binary_tree_t *walk;

	while (second && first)
	{
		walk = second;
		while (walk)
		{
			if (walk == first)
				return ((binary_tree_t *)walk);
			walk = walk->parent;
		}
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
