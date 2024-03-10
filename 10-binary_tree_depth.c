#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: a pointer to the node to measure the depth.
 * Return: 0 if tree is NULL else depth of tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t depth;

		depth = tree->parent ? binary_tree_depth(tree->parent) + 1 : 0;
		return (depth);
	}
	return (0);
}
