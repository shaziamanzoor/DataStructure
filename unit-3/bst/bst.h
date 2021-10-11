#ifndef BST_H
#define BST_H

#include "../binary_tree/binary_tree.h"

BinaryNode *bst_insert(BinaryNode *tree, BinaryEntry data);
BinaryNode *bst_search(BinaryNode *tree, BinaryEntry data);

#endif
