#include "binary_trees.h"

/**
 * binary_tree_size2 - measures the size of a binary tree (i.e number of nodes)
 * @tree: a pointer to the root node of the tree to measure the size.
 * Return: size of tree.
 */
size_t binary_tree_size2(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size = size + 1;
		size = size + binary_tree_size2(tree->left);
		size = size + binary_tree_size2(tree->right);
	}
	return (size);
}
