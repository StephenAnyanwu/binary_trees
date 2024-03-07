#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);
    printf("%d, %d, %d, %d\n", root->n,root->left->n,root->left->left->n, root->left->right->n);
    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);
    printf("%d, %d, %d, %d\n", root->n,root->right->n,root->right->left->n, root->right->right->n);
    return (0);
}
