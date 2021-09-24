#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

int main(void) {
  Node *values = NULL;
  for(int i = 0; i < 10; i++){
    values = ll_prepend(values, i);
  }
  ll_print(values);

  assert(ll_find(values, 11) == NULL);

  Node* value_5 = ll_find(values, 5);
  ll_insert_before(values, value_5, 11);
  ll_print(values);
  ll_insert_before(values, value_5, 12);
  ll_print(values);
  return 0;
}
