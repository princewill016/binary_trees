#include "binary_trees.h"
#include <limits.h>

/**
 * is_complete_tree - Checks if a binary tree is complete
 * @tree: Pointer to the root of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete_tree(const binary_tree_t *tree)
{
    size_t size, height, last_level_nodes, max_nodes;

    if (!tree)
        return (0);

    size = binary_tree_size(tree);
    height = binary_tree_height(tree);
    max_nodes = 1;

    /* Calculate max nodes possible for a complete tree of this height */
    for (size_t i = 0; i < height + 1; i++)
        max_nodes *= 2;
    max_nodes--;

    return (size <= max_nodes);
}

/**
 * binary_tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - Computes the size of a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    /* Check for complete tree property */
    if (!is_complete_tree(tree))
        return (0);

    /* Recursively check Max Heap property */
    return (heap_check_recursive(tree));
}

/**
 * heap_check_recursive - Recursively checks Max Heap property
 * @tree: Current node to check
 *
 * Return: 1 if valid, 0 otherwise
 */
int heap_check_recursive(const binary_tree_t *tree)
{
    if (!tree)
        return (1);

    /* Check left child */
    if (tree->left)
    {
        if (tree->n < tree->left->n)
            return (0);
        if (!heap_check_recursive(tree->left))
            return (0);
    }

    /* Check right child */
    if (tree->right)
    {
        if (tree->n < tree->right->n)
            return (0);
        if (!heap_check_recursive(tree->right))
            return (0);
    }

    return (1);
}
