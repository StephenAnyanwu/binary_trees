#include "binary_trees.h"

int is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL or not full, else 1.
 *
 * NOTE: A full binary tree is a binary tree in which all of the nodes
 * have either 0 or 2 offspring. In other terms, a full binary tree is
 * a binary tree in which all nodes, except the leaf nodes, have two offspring.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_full(tree));
}

/**
 * is_full - recursively check if binary tree meets full criteria.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 0 if tree is NULL or not full, else 1.
 */
int is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full(tree->left) == 0 ||
		    is_full(tree->right) == 0)
			return (0);
	}
	return (1);
}
