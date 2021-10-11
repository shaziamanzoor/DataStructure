
#include "bst.h"
#include "../binary_tree/binary_tree.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void print_visitor(BinaryNode *node) { printf("%d ", node->data); }


int main(void) {

  BinaryNode *tree = NULL;
  srand(time(NULL));
  
  for (int i = 0; i < 20; i++)
    tree = bst_insert(tree, rand() % 100);

  btree_inorder(tree, print_visitor);
  printf("\n");
  return 0;
}
