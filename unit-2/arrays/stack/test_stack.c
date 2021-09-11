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

  //initialize the stack
  stack_init(stack);

  //make sure its empty  
  assert(stack_is_empty(stack));

  //push the values into the stack
  for(int i = 0; a[i] != '\0'; i++)
    stack_push(stack, a[i]);
  
  assert(stack_count(stack) == 5); 
  assert(!stack_is_empty(stack));
  stack_debug(stack);

  // pop value and print it
  pop_and_print(stack);

  return 0;
}

