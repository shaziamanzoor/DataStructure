#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef StackEntry int;

typedef struct stack {
  StackEntry *elements;
  size_t size;
  int top;
} Stack;

Stack* stack_init(size_t stack_size);
int stack_pop(Stack* stack, StackEntry *value);
int stack_push(Stack* stack, StackEntry value);
int stack_top(Stack* stack, StackEntry *value);
bool stack_is_empty(Stack* stack);
bool stack_is_full(Stack* stack);
void stack_destroy(Stack* stack);

#define STACK_OK 0
#define STACK_ERROR_EMPTY -1
#define STACK_ERROR_FULL -2

#endif
