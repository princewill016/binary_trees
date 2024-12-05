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

/* Type definitions for various tree types */
typedef struct binary_tree_s heap_t;

/* Function prototypes */
int heap_extract(heap_t **root);
int binary_tree_is_heap(const binary_tree_t *tree);

/* Helper function prototypes */
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
int is_complete_tree(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
