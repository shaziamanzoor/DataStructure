#include <stdio.h>
#include <assert.h>
#include "stack.h"

void pop_and_print(Stack* stack){
   while (!stack_is_empty(stack)) {
      StackEntry item;
      stack_pop(stack, &item);
      printf("%c, ", item);
   }
   printf("\n");
}

int main(void){
  Stack s;
  Stack* stack = &s;
  StackEntry a[] = {'a', 'b', 'c', 'd', 'e', '\0'};

  stack_init(stack);
  assert(stack_is_empty(stack));

  for(int i = 0; a[i] != '\0'; i++)
    stack_push(stack, a[i]);

  assert(!stack_is_empty(stack));
  stack_print(stack);
  pop_and_print(stack);

  return 0;
}

