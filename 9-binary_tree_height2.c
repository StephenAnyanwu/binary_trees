#include "binary_trees.h"

long long int max(long long int num1, long long int num2);

/**
 * binary_tree_height2 - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: -1 if tree is NULL else height of tree.
 */
long long int  binary_tree_height2(const binary_tree_t *tree)
{
	long long int left_height, right_height;

	if (tree == NULL)
		return (-1);
	left_height = binary_tree_height2(tree->left);
	right_height = binary_tree_height2(tree->right);
	return (max(left_height, right_height) + 1);
}

/**
 * max - finds the maximum between two numbers.
 * @num1: first number.
 * @num2: second number.
 * Return: the maximum number.
 */
long long int max(long long int num1, long long int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
