#ifndef _BINTREE_H_
#define _BINTREE_H_

typedef int BinaryEntry;

typedef struct binary_node {
  BinaryEntry value;
  BinaryNode  *left;
  BinaryNode  *right;
} BinaryNode;

void bintree_create_node(BinaryEntry value);
bool bintree_is_empty(BinaryNode *tree);


#endif
