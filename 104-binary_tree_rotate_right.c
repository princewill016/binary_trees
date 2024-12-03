#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	/* If tree is NULL or has no left child, return the original tree */
	if (tree == NULL || tree->left == NULL)
		return (tree);

	/* Store the left child as the new root */
	new_root = tree->left;

	/* The right child of the new root becomes the left child of the old root */
	temp = new_root->right;
	new_root->right = tree;

	/* Update the parent pointers */
	tree->left = temp;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	/* If temp exists, update its parent */
	if (temp)
		temp->parent = tree;

	return (new_root);
}
