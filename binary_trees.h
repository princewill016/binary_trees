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

/* Function to create a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Function to insert a node as the left-child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Function to insert a node as the right-child of another node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Function to delete an entire binary tree */
void binary_tree_delete(binary_tree_t *tree);

/* Function to check if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Function to check if a node is a root */
int binary_tree_is_root(const binary_tree_t *node);

/* Function for pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Function for in-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Function for post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Function to measure the height of a binary tree */
size_t binary_tree_height(const binary_tree_t *tree);

/* Function to measure the depth of a node in a binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Function to measure the size of a binary tree */
size_t binary_tree_size(const binary_tree_t *tree);

/* Function to count nodes with at least 1 child in a binary tree */
size_t binary_tree_nodes(const binary_tree_t *tree);

size_t binary_tree_leaves(const binary_tree_t *tree);

size_t binary_tree_nodes(const binary_tree_t *tree);

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

int binary_tree_is_full(const binary_tree_t *tree);

size_t binary_tree_depth(const binary_tree_t *tree);
int is_leaf(const binary_tree_t *node);
int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, size_t current_depth,
                         size_t leaf_depth);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

size_t binary_tree_depth(const binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second);

#endif /* BINARY_TREES_H */
