#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

Node* cll_make_node(int data) {
  Node* node = calloc(1, sizeof(Node));
  node->next = node;
  node->data = data;
  return node;
}

Node* cll_insert(Node* head, int data) {
  Node* newNode = cll_make_node(data);

  if (head == NULL) return newNode;
  
  Node* p = head;
  for (; p->next != head; p = p->next);

  p->next = newNode;
  newNode->next = head;
  return newNode;
}
Node* cll_insert_after(Node* head, int data){
  Node* newNode = cll_make_node(data);

  if (head == NULL) return newNode;

  newNode->next = head->next;
  head->next = newNode;
  return newNode;
} 

Node* cll_find(Node* head, int data) {
  if (head == NULL) return NULL;
  
  Node* match = NULL;
  Node* p = head;
  do {
    if (p->data == data) {
      match = p;
      break;
    }

    p = p->next;
  } while (p != head);
    
  return match;
}

Node* cll_delete(Node* node) {
  if (node == NULL) return NULL;

  Node* p = node;
  for ( ; p->next != node; p = p->next);

  Node *head;
  if (p !=node) {
    p->next = node->next;
    head = node->next;
  } else {
    head = NULL;
  }

  free(node);
  return head;
}

void cll_print(Node* head) {
  if (head == NULL) return;

  Node* p = head;
  do {    
    printf("%d ", p->data);
    p = p->next;
  }while (p != head);
  
  printf("\n");
}
