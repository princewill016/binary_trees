#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Check if parent is NULL */
    if (parent == NULL)
        return (NULL);

    /* Create a new node */
    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);

    /* Set the new node's value */
    new_node->n = value;
    new_node->parent = parent;

    /* Handle existing left child */
    if (parent->left != NULL)
    {
        /* Current left child becomes left child of new node */
        new_node->left = parent->left;
        /* Update parent of the old left child */
        parent->left->parent = new_node;
    }
    else
    {
        /* No existing left child */
        new_node->left = NULL;
    }

    /* Set new node as parent's left child */
    parent->left = new_node;
    new_node->right = NULL;

    return (new_node);
}
