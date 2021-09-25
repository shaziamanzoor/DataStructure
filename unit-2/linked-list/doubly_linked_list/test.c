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
  DoubleNode *head = NULL;

  for (int i = 0; i < 10; i++)
    head = dll_prepend(head, i);

  print_list(head);

  assert(dll_find(head, 11) == NULL);

  DoubleNode* value_5 = dll_find(head, 5);
  dll_insert_before(value_5, 11);
  dll_insert_after(value_5, 12);
  print_list(head);
  
  printf("Deleting 5\n");
  head = dll_delete_node(head, value_5);
  print_list(head);
  
  assert(dll_find(head, 9) != NULL);                                                                                               
  DoubleNode *value_nine = dll_find(head, 9);                                                                                      
  printf("Deleting 9 \n");
  head = dll_delete_node(head, value_nine);                                                                                                        
  print_list(head);  
  assert(dll_find(head, 8) != NULL);
  
  DoubleNode *value_eight = dll_find(head, 8);                                                                                     
  printf("Deleting 8 \n");
  head = dll_delete_node(head, value_eight);
  print_list(head);  
 
  return 0;
}

