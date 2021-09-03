#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

typedef int Data;

typedef struct double_node {
  Data value;
  struct double_node *prev;
  struct double_node *next;
} DoubleNode;

DoubleNode* dll_create_node(Data value);
DoubleNode* dll_prepend(DoubleNode* node, Data value);
void dll_insert_before(DoubleNode* node, Data value);
void dll_insert_after(DoubleNode* node, Data value);
void dll_for_each(DoubleNode* head, void (*fn) (DoubleNode*));
DoubleNode* dll_find(DoubleNode* head, Data value);

#endif
