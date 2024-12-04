#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_helper - Recursive helper function to check if tree is a valid BST
 * @tree: Pointer to the current node
 * @min: Minimum allowed value for the current node
 * @max: Maximum allowed value for the current node
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	/* Base case: empty tree is considered a valid BST */
	if (tree == NULL)
		return (1);

	/* Check if current node's value is within the allowed range */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Recursively check left and right subtrees */
	/* Left subtree must have values less than current node */
	/* Right subtree must have values greater than current node */
	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* If tree is NULL, it's not a valid BST */
	if (tree == NULL)
		return (0);

	/* Use helper function with initial min and max as INT_MIN and INT_MAX */
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
