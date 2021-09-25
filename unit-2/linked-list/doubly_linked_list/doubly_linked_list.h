#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

typedef int data;

typedef struct double_node {
  data value;
  struct double_node *prev;
  struct double_node *next;
} DoubleNode;

DoubleNode* dll_create_node(data value);
DoubleNode* dll_prepend(DoubleNode* head, data value);
void dll_insert_before(DoubleNode* node, data value);
void dll_insert_after(DoubleNode* node, data value);
DoubleNode* dll_delete_node(DoubleNode *head, DoubleNode *node);
DoubleNode* dll_find(DoubleNode* head, data value);

#endif
