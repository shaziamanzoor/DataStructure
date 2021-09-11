#include <stdbool.h>
#define MAXSTACK 100

#ifndef STACK_H_
#define STACK_H_

typedef char StackEntry;

typedef struct stack{
  int tos;
  StackEntry elements[MAXSTACK];
}Stack;

void stack_init(Stack *stack);
void stack_push(Stack *stack, StackEntry item);
void stack_pop(Stack *stack, StackEntry* item);
bool stack_is_empty(Stack *stack);
bool stack_is_full(Stack *stack);
void stack_clear(Stack *stack);
void stack_debug(Stack *stack);
int stack_count(Stack *stack);
#endif
