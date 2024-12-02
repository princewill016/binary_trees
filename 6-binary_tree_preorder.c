#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    /* If tree or func is NULL, do nothing */
    if (tree == NULL || func == NULL)
        return;

    /* First, call the function on the current node's value */
    func(tree->n);

    /* Then recursively traverse left subtree */
    binary_tree_preorder(tree->left, func);

    /* Then recursively traverse right subtree */
    binary_tree_preorder(tree->right, func);
}
