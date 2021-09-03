#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../linked_list/linked_list.h"

Stack* stack_init(void) {
  Stack *stack = calloc(1, sizeof(Stack));
  stack->head = NULL;
  return stack;
}

int stack_pop(Stack* stack, int *value) {
  if (stack_is_empty(stack))
    return STACK_ERROR_EMPTY;

  *value = stack->head->data;
  Node* node = stack->head;
  stack->head = node->next;
  free(node);
  return STACK_OK;
}

int stack_push(Stack* stack, int value){
  stack->head = ll_prepend(stack->head, value);
  return STACK_OK;
}

int stack_top(Stack* stack, int *value) {
  if (stack_is_empty(stack))
    return STACK_ERROR_EMPTY;

  *value = stack->head->data;
  return STACK_OK;
}

bool stack_is_empty(Stack* stack) {
  return stack->head == NULL;
}

void stack_destroy(Stack* stack) {
  free(stack);
}

