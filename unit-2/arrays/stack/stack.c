#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

static void error(char* message) {
  fprintf(stderr, "Error: %s\n", message);
  exit(-1);
}

void stack_init(Stack *s){
  s->tos = 0;
}

bool stack_is_full(Stack *s){
  return s->tos >= MAXSTACK;
}

bool stack_is_empty(Stack* s){
  return s->tos == 0;
}

void stack_print(Stack *s){
  for(int i = 0; i < s->tos; i++)
    printf("%c, ", s->entry[i]);
  printf("\n");
}

void stack_push(Stack *s, StackEntry item){
  if(stack_is_full(s))
    error("Stack is full");
  else  
    s->entry[s->tos++] = item;
  
}

void stack_pop(Stack* s, StackEntry *item){
  if(stack_is_empty(s))
    error("Stack is empty");
  else{
    *item = s->entry[--s->tos];
  }
}

void stack_clear(Stack* s) {
  s->tos = 0;
}

