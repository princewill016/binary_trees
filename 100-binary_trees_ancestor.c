#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node in the tree
 * @node: Pointer to the node to measure depth
 *
 * Return: Depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node->parent)
	{
		depth++;
		node = node->parent;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *deep, *shallow;
	size_t depth_first, depth_second, depth_diff;

	/* Check for NULL inputs */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Calculate depths of both nodes */
	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/* Determine which node is deeper */
	if (depth_first > depth_second)
	{
		deep = first;
		shallow = second;
		depth_diff = depth_first - depth_second;
	}
	else
	{
		deep = second;
		shallow = first;
		depth_diff = depth_second - depth_first;
	}

	/* Bring the deeper node up to the same level as the shallower node */
	while (depth_diff--)
		deep = deep->parent;

	/* Find the lowest common ancestor */
	while (deep != shallow)
	{
		deep = deep->parent;
		shallow = shallow->parent;
	}

	return ((binary_tree_t *)deep);
}
