#ifndef _STACK_H
#define _STACK_H

#include "../linked_list/linked_list.h"
#include <stdbool.h>

typedef struct stack {
  Node* head;
} Stack;

Stack* stack_init();
int stack_pop(Stack* stack, int *value);
int stack_push(Stack* stack, int value);
int stack_top(Stack* stack, int *value);
bool stack_is_empty(Stack* stack);
void stack_destroy(Stack* stack);

#define STACK_OK 0
#define STACK_ERROR_EMPTY -1

#endif
