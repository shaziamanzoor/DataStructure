#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doubly_linked_list.h"

void print_value(DoubleNode *node) {
  printf("%d ", node->value);
}

void print_list(DoubleNode *head) {
  dll_for_each(head, print_value);
  printf("\n");
}

int main(void) {
  DoubleNode *values = NULL;

  for (int i = 0; i < 10; i++)
    values = dll_prepend(values, i);

  print_list(values);

  assert(dll_find(values, 11) == NULL);

  DoubleNode* value_5 = dll_find(values, 5);
  dll_insert_before(value_5, 11);
  dll_insert_after(value_5, 12);

  print_list(values);
  return 0;
}

