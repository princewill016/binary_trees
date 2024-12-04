#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current, *parent;

    /* If tree is NULL, create a new root node */
    if (tree == NULL)
        return (NULL);

    /* If root is NULL, create a new root node */
    if (*tree == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        *tree = new_node;
        return (new_node);
    }

    current = *tree;
    parent = NULL;

    /* Traverse the tree to find the insertion point */
    while (current != NULL)
    {
        parent = current;

        /* If value already exists, ignore and return NULL */
        if (value == current->n)
            return (NULL);

        /* Decide to go left or right based on value */
        if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    /* Create new node */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* Insert the node */
    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (new_node);
}

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
bst_t *binary_tree_node(bst_t *parent, int value)
{
    bst_t *new_node;

    new_node = malloc(sizeof(bst_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}
