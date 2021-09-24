#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

#define MAX_EXPRESSION_SIZE 255

int to_number(char c) {
  return c - '0';
}

bool is_operator(char c) {
  return c == '*' || c == '/' || c == '+' || c == '-';
}

int operate(char op, int x, int y) {
  int z = 0;
  
  switch (op) {
  case '+':
    z = x + y;
    break;
    
  case '-':
    z = x - y;
    break;
    
  case '*':
    z = x * y;
    break;
    
  case '/':
    z = x / y; //TODO: Check y != 0
    break;
  }

  return z;
}

int evaluate_reverse_polish(char* expression, int* result) {
  Stack *stack = stack_create(MAX_EXPRESSION_SIZE); 

  for (char *p = expression; (*p) != '\0'; p++) {
    char c = *p;

    if (!is_operator(c)) {
      if (stack_push(stack, to_number(c)) != STACK_OK)
        return -1;
    } else {
      int x;
      int y;
      
      if (stack_pop(stack, &y) != STACK_OK)
        return -1;

      if (stack_pop(stack, &x) != STACK_OK)
        return -1;

      int z = operate(c, x, y);
      if (stack_push(stack, z) != STACK_OK)
        return -1;

    }
  }

  if (stack_is_empty(stack))
    return -1;

  stack_pop(stack, result);

  return stack_is_empty(stack) ? 0 : -1;
}

      
int main(int argc, char* argv[]) {

  if (argc != 2) {
    fprintf(stderr, "Wrong usage: %s reverse-polish-expression\n", argv[0]);
    return -1;
  }
  
  char* expression = argv[1];
  int value;

  if (evaluate_reverse_polish(expression, &value) != 0) {
    printf("The expression is not in reverse polish format\n");
    return -1;
  }
  
  printf("The value of expression %s is %d\n", expression, value);
  return 0;
}
