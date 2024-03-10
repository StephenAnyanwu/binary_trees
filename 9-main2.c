#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    long long int  height;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_height2(root);
    printf("Height from %d: %lld\n", root->n, height);
    height = binary_tree_height2(root->right);
    printf("Height from %d: %lld\n", root->right->n, height);
    height = binary_tree_height2(root->left->right);
    printf("Height from %d: %lld\n", root->left->right->n, height);
    return (0);
}
