#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack* stack_init(size_t stack_size) {
  Stack* stack = calloc(1, sizeof(Stack));
  stack->size = stack_size;
  stack->elements = calloc(stack_size, sizeof(int));
  stack->top = -1;
  return stack;
}

int stack_pop(Stack* stack, StackEntry *value) {
  if (stack_is_empty(stack))
    return STACK_ERROR_EMPTY;

  *value = stack->elements[stack->top];
  stack->top--;
  return STACK_OK;
}

int stack_push(Stack* stack, StackEntry value) {
  if (stack_is_full(stack))
    return STACK_ERROR_FULL;

  stack->elements[++stack->top] = value;
  return STACK_OK;
}
  
int stack_top(Stack* stack, StackEntry *value) {
  if (stack_is_full(stack))
    return STACK_ERROR_FULL;

  *value = stack->elements[stack->top];
  return STACK_OK;
}

bool stack_is_empty(Stack* stack) {
  return stack->top == -1;
}

bool stack_is_full(Stack* stack) {
  return stack->top >= (int)(stack->size - 1);
}

void stack_destroy(Stack* stack) {
  free(stack->elements);
  free(stack);
}

