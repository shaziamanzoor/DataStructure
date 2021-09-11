#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

static void error(char* message) {
  fprintf(stderr, "Error: %s\n", message);
  exit(-1);
}

void stack_init(Stack *stack){
  stack->tos = 0;
}

bool stack_is_full(Stack *stack){
  return stack->tos >= MAXSTACK;
}

bool stack_is_empty(Stack *stack){
  return stack->tos == 0;
}

void stack_debug(Stack *stack){
  for(int i = 0; i < stack->tos; i++)
    printf("%c, ", stack->elements[i]);
  printf("\n");
}

void stack_push(Stack *stack, StackEntry item){
  if(stack_is_full(stack))
    error("Stack is full");
  else  
    stack->elements[stack->tos++] = item;
  
}

void stack_pop(Stack *stack, StackEntry *item){
  if(stack_is_empty(stack))
    error("Stack is empty");
  else{
    *item = stack->elements[--stack->tos];
  }
}

void stack_clear(Stack *stack) {
  stack->tos = 0;
}
int stack_count(Stack *stack){
//	int count = 0;
//	for(int i = 0; i < stack->tos; i++)
//		count++;
	return stack->tos;
}
