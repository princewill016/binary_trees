#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    /* If node is NULL, return 0 */
    if (node == NULL)
        return (0);

    /* Check if the node has no children (both left and right are NULL) */
    if (node->left == NULL && node->right == NULL)
        return (1);

    /* If node has any children, it's not a leaf */
    return (0);
}
