#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in a binary tree
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * Return: Number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Check if the node has at least one child */
	if (tree->left != NULL || tree->right != NULL)
	{
		/* If node has at least one child, count this node 
		 * and recursively count nodes in left and right subtrees */
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	}

	/* If node has no children, return 0 */
	return (0);
}
