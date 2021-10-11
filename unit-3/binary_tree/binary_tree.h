#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdbool.h>

typedef int BinaryEntry;

typedef struct binary_node {
  struct binary_node *left;
  struct binary_node *right;
  BinaryEntry data;
} BinaryNode;

typedef void (*Visitor) (BinaryNode *node);

BinaryNode *btree_make_node(BinaryEntry data);
BinaryNode *btree_insert_left(BinaryNode *tree, BinaryEntry data);
BinaryNode *btree_insert_right(BinaryNode *tree, BinaryEntry data);
bool btree_is_empty(BinaryNode *tree);

void btree_preorder(BinaryNode *tree, Visitor visitor);
void btree_postorder(BinaryNode *tree, Visitor visitor);
void btree_inorder(BinaryNode *tree, Visitor visitor);

#endif

  
  
