#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    /* If tree or func is NULL, do nothing */
    if (tree == NULL || func == NULL)
        return;

    /* First, recursively traverse left subtree */
    binary_tree_inorder(tree->left, func);

    /* Then process the current node */
    func(tree->n);

    /* Finally, recursively traverse right subtree */
    binary_tree_inorder(tree->right, func);
}
