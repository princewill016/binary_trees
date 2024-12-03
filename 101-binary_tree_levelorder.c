#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current;
	binary_tree_t **queue;
	int front = 0, rear = 0;
	size_t tree_height, queue_size;

	/* Check for NULL inputs */
	if (tree == NULL || func == NULL)
		return;

	/* Calculate tree height to determine queue size */
	tree_height = binary_tree_height(tree) + 1;
	queue_size = (1 << tree_height) - 1; /* 2^height - 1 */

	/* Allocate queue */
	queue = malloc(queue_size * sizeof(binary_tree_t *));
	if (queue == NULL)
		return;

	/* Enqueue root node */
	queue[rear++] = (binary_tree_t *)tree;

	/* Process nodes level by level */
	while (front < rear)
	{
		/* Dequeue and process current node */
		current = queue[front++];

		/* Call function on current node's value */
		func(current->n);

		/* Enqueue left child if exists */
		if (current->left)
			queue[rear++] = current->left;

		/* Enqueue right child if exists */
		if (current->right)
			queue[rear++] = current->right;
	}

	/* Free the queue */
	free(queue);
}

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
