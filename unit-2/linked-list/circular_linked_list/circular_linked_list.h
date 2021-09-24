
#ifndef _CIRCULAR_LINKED_LIST_H_
#define _CIRCULAR_LINKED_LIST_H_

typedef struct node {
  int data;
  struct node *next;
} Node;

Node* cll_make_node(int data);
Node* cll_insert(Node* head, int data);
Node* cll_insert_after(Node* head, int data);
Node* cll_find(Node* head, int data);
Node* cll_delete(Node* head);
void cll_print(Node* head);

#endif
