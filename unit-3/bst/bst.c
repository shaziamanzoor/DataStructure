#include <stdlib.h>
#include "bst.h"
#include "../binary_tree/binary_tree.h"

BinaryNode* bst_insert(BinaryNode *tree, BinaryEntry data) {
  if (!tree)
    return btree_make_node(data);

  if (data < tree->data)
    tree->left = bst_insert(tree->left, data);
  else if (data > tree->data)
    tree->right = bst_insert(tree->right, data);

  return tree;
}

BinaryNode* bst_search(BinaryNode *tree, BinaryEntry data) {
  if (!tree) return NULL;

  if (data == tree->data)
    return tree;
  else if (data < tree->data)
    return bst_search(tree->left, data);
  else
    return bst_search(tree->right, data);
}

  
