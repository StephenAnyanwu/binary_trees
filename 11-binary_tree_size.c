#include "binary_trees.h"

size_t binary_subtree_size(const binary_tree_t *tree);

/**
 * binary_tree_size -  measures the size of a binary tree (i.e number of nodes)
 * @tree: a pointer to the root node of the tree to measure the size.
 * Return: 0 if tree is NULL else size of tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;

	size = binary_subtree_size(tree);
	if (size)
		return (++size);
	return (size);
}

/**
 * binary_subtree_size - measures the size of subtree(s) of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the size.
 * Return: 0 if tree is NULL else size of tree.
 */
size_t binary_subtree_size(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left, right;

		left = tree->left ? 1 + binary_subtree_size(tree->left) : 0;
		right = tree->right ? 1 + binary_subtree_size(tree->right) : 0;
		return (left + right);
	}
	return (0);
}
