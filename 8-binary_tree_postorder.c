#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    /* If tree or func is NULL, do nothing */
    if (tree == NULL || func == NULL)
        return;

    /* First, recursively traverse left subtree */
    binary_tree_postorder(tree->left, func);

    /* Then recursively traverse right subtree */
    binary_tree_postorder(tree->right, func);

    /* Finally, process the current node */
    func(tree->n);
}
