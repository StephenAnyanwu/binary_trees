#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int is_perfect(const binary_tree_t *tree, size_t d_l, size_t *l);

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
	size_t d_l, l = 0;

	d_l = binary_tree_height(tree);
	return (is_perfect(tree, d_l, &l));
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: 0 if tree is NULL else height of tree.
 *
 * This will help us to know the deepest level of the binary tree.
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

/**
 * is_perfect - recursively check is a binary tree is perfect.
 * It ckecks if:
 * 1. all leaves are at the level.
 * 2. all internal nodes have two child nodes.
 * @tree: a pointer to the root node of the tree to check.
 * @d_l: deepest level of the binary tree.
 * @l: level of @tree.
 * Return: 0 if tree is NULL or tree not perfect, else 1.
 */
int is_perfect(const binary_tree_t *tree, size_t d_l, size_t *l)
{
	if (tree == NULL)
		return (1);
	/* If leaves, return 1 if their level same as the deepest level */
	/* otherwise return 0 */
	if (tree->left == NULL && tree->right == NULL)
		return (d_l == (*l) + 1 ? 1 : 0);
	/* If internal node and one child node is empty */
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect(tree->left, d_l, (*l) + 1) &&
		is_perfect(tree->right, d_l, (*l) + 1));
}
