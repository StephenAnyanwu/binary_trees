#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a
 * binary tree.
 * @node: A pointer to the node to find the sibling.
 * Return: NULL if @node is NULL, parent is NULL or @node has
 * no sibling, else a pointer to the sibling @node.
 *
 * Note:
 * Two nodes are said to be siblings if they are present at the
 * same level, and their parents are the same.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
