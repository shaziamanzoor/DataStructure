#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

void print_visitor(BinaryNode *node) {
  printf("%d ", node->data);
}
int main(void) {
  BinaryNode *tree = btree_make_node(1);
  tree->left = btree_make_node(2);
  tree->right = btree_make_node(3);
  
  BinaryNode *tree1 = tree->left;
  tree1->left = btree_make_node(4);
  tree1->right = btree_make_node(5);

  BinaryNode *tree2 = tree->right;                                                                                                       
  tree2->left = btree_make_node(6);                                                                                                     
  tree2->right = btree_make_node(7); 

  printf("Preorder traversal \n");
  btree_preorder(tree, print_visitor);
  printf("\nPostorder traversal \n");
  btree_postorder(tree, print_visitor);
  printf("\nInorder traversal \n");
  btree_inorder(tree, print_visitor);
  return 0;
}
