#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If node is NULL or parent is NULL, return NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is the left child, return right child of parent */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is the right child, return left child of parent */
	if (node->parent->right == node)
		return (node->parent->left);

	/* This line should never be reached, but added for completeness */
	return (NULL);
}
