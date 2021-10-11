#include <stdlib.h>
#include "binary_tree.h"

BinaryNode* btree_make_node(BinaryEntry data) {
  BinaryNode *node = calloc(1, sizeof(BinaryNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

BinaryNode *btree_insert_left(BinaryNode *tree, BinaryEntry data){
  tree->left = btree_make_node(data);
  return tree;
}

BinaryNode *btree_insert_right(BinaryNode *tree, BinaryEntry data){
  tree->right = btree_make_node(data);
  return tree;
}

bool btree_is_empty(BinaryNode *btree) { return btree == NULL; }

void btree_preorder(BinaryNode *tree, Visitor visitor) {
  if (!btree_is_empty(tree)) {
    visitor(tree);
    btree_preorder(tree->left, visitor);
    btree_preorder(tree->right, visitor);
  }
}
void btree_postorder(BinaryNode *tree, Visitor visitor) {
  if (!btree_is_empty(tree)) {
    btree_postorder(tree->left, visitor);
    btree_postorder(tree->right, visitor);
    visitor(tree);
  }
}
void btree_inorder(BinaryNode *tree, Visitor visitor) {
  if(!btree_is_empty(tree)) {
    btree_inorder(tree->left, visitor);
    visitor(tree);
    btree_inorder(tree->right, visitor);
  }
}

      
