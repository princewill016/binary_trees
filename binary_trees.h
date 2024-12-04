#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* Type definitions for different tree types */
typedef struct binary_tree_s bst_t;

/* Function prototypes */
/* BST Validation Function */
int binary_tree_is_bst(const binary_tree_t *tree);

/* BST Insertion Function */
bst_t *bst_insert(bst_t **tree, int value);

#endif /* BINARY_TREES_H */
