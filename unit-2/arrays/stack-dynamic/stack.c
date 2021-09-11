#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack* stack_create(size_t stack_size) {
  Stack* stack = calloc(1, sizeof(Stack));
  stack->size = stack_size;
  stack->elements = calloc(stack_size, sizeof(StackEntry));
  stack->top = 0;
  return stack;
}

int stack_pop(Stack* stack, StackEntry *item) {
  if (stack_is_empty(stack))
    return STACK_ERROR_EMPTY;

  *item = stack->elements[--stack->top];
  return STACK_OK;
}

int stack_push(Stack* stack, StackEntry item) {
  if (stack_is_full(stack))
    return STACK_ERROR_FULL;

  stack->elements[stack->top++] = item;
  return STACK_OK;
}
  
int stack_top(Stack* stack, StackEntry *item) {
  if (stack_is_empty(stack))
    return STACK_ERROR_EMPTY;//stack empty

  *item = stack->elements[stack->top - 1];
  return STACK_OK;
}

bool stack_is_empty(Stack* stack) {
  return stack->top == 0;
}

bool stack_is_full(Stack* stack) {
  return stack->top >= stack->size ; 
}

void stack_destroy(Stack* stack) {
  free(stack->elements);
  free(stack);
}

