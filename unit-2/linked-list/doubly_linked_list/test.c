#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doubly_linked_list.h"

void print_list(DoubleNode *head) {
  for (DoubleNode* p = head; p != NULL; p = p->next)
    printf("%d ", p->value);
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
  dll_delete_node(value_5);
  print_list(values);
  return 0;
}

