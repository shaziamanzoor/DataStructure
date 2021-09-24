#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circular_linked_list.h"

int main(void) {
  Node *head = NULL;

  for (int i = 0; i < 10; i++) {
    head = cll_insert(head, i);
  }
  
  cll_print(head);
  Node *any = cll_find(head, 5);
  assert(any->data == 5);
  head = cll_delete(any);

  cll_print(head);
  cll_insert_after(head, 100);
  cll_print(head);
  return 0;
}


  
