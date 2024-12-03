#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue;
	int front = 0, rear = 0, flag = 0;
	size_t tree_height, queue_size;

	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Calculate tree height to determine queue size */
	tree_height = binary_tree_height(tree) + 1;
	queue_size = (1 << tree_height) - 1; /* 2^height - 1 */

	/* Allocate queue */
	queue = malloc(queue_size * sizeof(binary_tree_t *));
	if (queue == NULL)
		return (0);

	/* Enqueue root node */
	queue[rear++] = tree;

	/* Process nodes level by level */
	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		/* Enqueue left child */
		if (current->left)
		{
			/* If we've already seen a non-full node, only full nodes are allowed */
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
		}
		else
		{
			/* Mark that we've seen a non-full node */
			flag = 1;
		}

		/* Enqueue right child */
		if (current->right)
		{
			/* If we've already seen a non-full node, only full nodes are allowed */
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->right;
		}
		else
		{
			/* Mark that we've seen a non-full node */
			flag = 1;
		}
	}

	/* Free the queue and return success */
	free(queue);
	return (1);
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
