#include "binary_trees.h"

/**
 * binary_tree_insert_right - nserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure or if parent
 * is NULL
 * If parent already has a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *present_right_child;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL || parent == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	if (parent->left)
	{
		present_right_child = parent->right;
		parent->right = new_node;
		new_node->parent = parent;
		new_node->right = present_right_child;
		present_right_child->parent = new_node;
		return (present_right_child);
	}
	parent->right = new_node;
	return (new_node);
}
