#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

DoubleNode* dll_create_node(Data value) {
  DoubleNode *node = calloc(1, sizeof(DoubleNode));
  node->value = value;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

DoubleNode* dll_prepend(DoubleNode* node, Data value) {
  DoubleNode* newNode = dll_create_node(value);
  newNode->next = node;
  if (node)
    node->prev = newNode;
  return newNode;
}

void dll_insert_before(DoubleNode* node, Data value){
  DoubleNode* newNode = dll_create_node(value);
  DoubleNode* origPrev = node->prev;
  node->prev = newNode;
  newNode->prev = origPrev;
  newNode->next = node;
  if (origPrev)
    origPrev->next = newNode;
}

void dll_insert_after(DoubleNode* node, Data value){
  DoubleNode* newNode = dll_create_node(value);
  DoubleNode* origNext = node->next;
  node->next = newNode;
  newNode->prev = node;
  newNode->next = origNext;
  if (origNext)
    origNext->prev = newNode;
}

void dll_for_each(DoubleNode *head, void (*fn)(DoubleNode*)) {
  for (DoubleNode* p = head; p != NULL; p = p->next) fn(p);
}

DoubleNode* dll_find(DoubleNode *head, Data value) {
  DoubleNode *p;
  for (p = head; p != NULL && p->value != value; p = p->next);
  return p;
}


