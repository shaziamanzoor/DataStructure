#include <stdbool.h>

#ifndef _STACK_H
#define _STACK_H

typedef struct stack {
  int *elements;
  size_t size;
  int top;
} Stack;

Stack* stack_init(size_t stack_size);
int stack_pop(Stack* stack, int *value);
int stack_push(Stack* stack, int value);
int stack_top(Stack* stack, int *value);
bool stack_is_empty(Stack* stack);
bool stack_is_full(Stack* stack);
void stack_destroy(Stack* stack);

#define STACK_OK 0
#define STACK_ERROR_EMPTY -1
#define STACK_ERROR_FULL -1

#endif
