#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root of the heap
 *
 * Return: Value of the extracted root, or 0 if extraction fails
 */
int heap_extract(heap_t **root)
{
    heap_t *heap_root, *last_node, *current, *child;
    int extracted_value;
    int heap_size = 0;

    /* Check if root or *root is NULL */
    if (!root || !*root)
        return (0);

    /* Store the root node and its value */
    heap_root = *root;
    extracted_value = heap_root->n;

    /* If only root exists, free and return its value */
    if (!heap_root->left && !heap_root->right)
    {
        *root = NULL;
        free(heap_root);
        return (extracted_value);
    }

    /* Find the last level-order node */
    current = heap_root;
    while (current->left || current->right)
    {
        heap_size++;
        current = current->left ? current->left : current->right;
    }
    last_node = heap_root;

    /* Traverse to find the parent of the last node */
    for (int i = 0; i < heap_size / 2; i++)
    {
        if (i == (heap_size / 2) - 1)
        {
            if (!last_node->right)
                last_node = last_node->left;
            else
                last_node = last_node->right;
        }
        last_node = last_node->left ? last_node->left : last_node->right;
    }

    /* Replace root with last node */
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    last_node->parent = heap_root->parent;
    last_node->left = heap_root->left;
    last_node->right = heap_root->right;

    if (last_node->left)
        last_node->left->parent = last_node;
    if (last_node->right)
        last_node->right->parent = last_node;

    *root = last_node;
    free(heap_root);

    /* Heapify to maintain max heap property */
    current = last_node;
    while (1)
    {
        child = NULL;
        if (current->left && current->right)
            child = current->left->n > current->right->n ? current->left : current->right;
        else if (current->left)
            child = current->left;
        else if (current->right)
            child = current->right;

        if (!child || current->n >= child->n)
            break;

        /* Swap values */
        int temp = current->n;
        current->n = child->n;
        child->n = temp;

        current = child;
    }

    return (extracted_value);
}
