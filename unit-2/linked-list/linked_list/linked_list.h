
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct node {
  int data;
  struct node *next;
} Node;

/**
 * Create a new node for the given data
 */
Node* ll_make_node(int data);

/**
 * Prepend new data to the head of the linked list
 */
Node* ll_prepend(Node* head, int data);

/**
 * Insert data before a given node
 */
Node* ll_insert_before(Node* head, Node* mark, int data);

/**
 * Find the first node with a given data
 */
Node* ll_find(Node* head, int data);

/**
 * Delete a given node from the list
 */
Node* ll_delete(Node* head, Node *node);

/**
 * Print elements of the list
 */
void ll_print(Node* head);

#endif
