#include "binary_trees.h"

unsigned char is_leaf_node(const binary_tree_t *node);
size_t node_depth(const binary_tree_t *node);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, size_t l_d, size_t level);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 * Return: 0 if NULL or tree not perfect, else 1.
 *
 * NOTE: A perfect binary tree is a type of binary tree in which every
 * internal node has exactly two child nodes and all the leaf nodes are
 * at the same level.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, node_depth(get_leaf(tree)), 0));
}

/**
 * is_leaf_node - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 * Return: 1 if @node is leaf, else 0.
 */
unsigned char is_leaf_node(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * node_depth - Finds the depth of a node in a binary tree.
 * @node: A pointer to the node to find its depth.
 * Return: The depth of @node
 */
size_t node_depth(const binary_tree_t *node)
{
	return (node->parent != NULL ? 1 + node_depth(node->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf_node(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Recursively checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * @l_d: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 * Return: 0 if tree is NULL or tree not perfect, else 1.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t l_d, size_t level)
{
	if (is_leaf_node(tree))
		return (level == l_d ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, l_d, level + 1) &&
		is_perfect_recursive(tree->right, l_d, level + 1));
}
