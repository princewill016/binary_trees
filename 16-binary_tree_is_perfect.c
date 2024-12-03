#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

/**
 * is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int is_leaf(const binary_tree_t *node)
{
	return (node != NULL && node->left == NULL && node->right == NULL);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaf_depth = 0;
	const binary_tree_t *current;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Find the depth of the first leaf */
	current = tree;
	while (current->left)
		current = current->left;
	leaf_depth = binary_tree_depth(current);

	/* Use a helper function to recursively check if tree is perfect */
	return (is_perfect_recursive(tree, 0, leaf_depth));
}

/**
 * is_perfect_recursive - Recursively checks if a binary tree is perfect
 * @tree: Pointer to the current node
 * @current_depth: Current depth of the node
 * @leaf_depth: Depth of leaves in the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t current_depth, 
						  size_t leaf_depth)
{
	/* If tree is NULL, it's not perfect */
	if (tree == NULL)
		return (0);

	/* If it's a leaf, check if it's at the correct depth */
	if (is_leaf(tree))
		return (current_depth == leaf_depth);

	/* If node doesn't have both children, it's not perfect */
	if ((tree->left == NULL) != (tree->right == NULL))
		return (0);

	/* Recursively check left and right subtrees */
	return (is_perfect_recursive(tree->left, current_depth + 1, leaf_depth) &&
			is_perfect_recursive(tree->right, current_depth + 1, leaf_depth));
}
