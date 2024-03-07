#include "binary_trees.h"

/**
 * binary_tree_insert_left - nserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure or if parent
 * is NULL
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *present_left_child;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL || parent == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	if (parent->left)
	{
		present_left_child = parent->left;
		parent->left = new_node;
		new_node->parent = parent;
		new_node->left = present_left_child;
		present_left_child->parent = new_node;
		return (present_left_child);
	}
	parent->left = new_node;
	return (new_node);
}
