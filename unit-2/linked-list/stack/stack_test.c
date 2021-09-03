#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main(void){
  Stack* stack = stack_init();
  assert(stack_is_empty(stack));
  
  for (int i = 0; i < 10; i++)
    assert(stack_push(stack, i) == STACK_OK);

  assert(!stack_is_empty(stack));
  
  ll_print(stack->head);

  int value;
  assert(stack_pop(stack, &value) == STACK_OK);
  assert(value == 9);

  for (int i = 8; i >= 0; i--) {
    assert(stack_pop(stack, &value) == STACK_OK);
    assert(value == i);
  }

  assert(stack_is_empty(stack));
  assert(stack_pop(stack, &value) == STACK_ERROR_EMPTY);
  return 0;
}

    
