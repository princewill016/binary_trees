#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Recursively calculate height of left and right subtrees */
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the maximum height */
	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Calculate height of left subtree */
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	
	/* Calculate height of right subtree */
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the difference between left and right subtree heights */
	return (left_height - right_height);
}
