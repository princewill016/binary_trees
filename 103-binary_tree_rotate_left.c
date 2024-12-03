#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	/* If tree is NULL or has no right child, return the original tree */
	if (tree == NULL || tree->right == NULL)
		return (tree);

	/* Store the right child as the new root */
	new_root = tree->right;

	/* The left child of the new root becomes the right child of the old root */
	temp = new_root->left;
	new_root->left = tree;

	/* Update the parent pointers */
	tree->right = temp;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	/* If temp exists, update its parent */
	if (temp)
		temp->parent = tree;

	return (new_root);
}
