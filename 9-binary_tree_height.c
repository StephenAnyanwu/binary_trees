#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: 0 if tree is NULL else height of tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height, right_height;

		left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
		right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;
		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}
