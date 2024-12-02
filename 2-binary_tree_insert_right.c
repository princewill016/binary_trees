#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

    /* Handle existing right child */
    if (parent->right != NULL)
    {
        /* Current right child becomes right child of new node */
        new_node->right = parent->right;
        /* Update parent of the old right child */
        parent->right->parent = new_node;
    }
    else
    {
        /* No existing right child */
        new_node->right = NULL;
    }

    /* Set new node as parent's right child */
    parent->right = new_node;
    new_node->left = NULL;

    return (new_node);
}
