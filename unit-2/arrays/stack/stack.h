#include <stdbool.h>
#define MAXSTACK 100

#ifndef STACK_H_
#define STACK_H_

typedef char StackEntry;

typedef struct stack{
  int tos;
  StackEntry entry[MAXSTACK];
}Stack;

void stack_init(Stack *s);
void stack_push(Stack *s, StackEntry item);
void stack_pop(Stack *s, StackEntry* item);
bool stack_is_empty(Stack *s);
bool stack_is_full(Stack *s);
void stack_clear(Stack *s);
void stack_print(Stack *s);

#endif
