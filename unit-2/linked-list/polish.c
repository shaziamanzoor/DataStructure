#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack/stack.h"

bool is_operator(int c) {
  return c == '*' || c == '/' || c == '+' || c == '-';
}

int run_operation(int op, int x, int y) {
  switch(op) {
  case '+': return x + y;
  case '-': return x - y;
  case '*': return x * y;
  case '/': return x / y;
  default: return 0;
  }
}

int to_number(int c) {
  return c - '0';
}

int evaluate_polish(const char* str, int *result) {
  Stack* stack = stack_init();

  for (const char* p = str; *p != '\0'; p++) {
    int c = (int)*p;

    if (is_operator(c)) stack_push(stack, c);
    else {      
      int top;
      if (stack_top(stack, &top) != STACK_OK)
        return -1;

      if (is_operator(top))
        stack_push(stack, to_number(c));
      else {
        int op;
        c = to_number(c);
        if (stack_pop(stack, &top) != STACK_OK)
          return -1;
        
        if (stack_pop(stack, &op) != STACK_OK)
          return -1;
        
        int result = run_operation(op, top, c);
        stack_push(stack, result);
      }
    }
  }

  while (!stack_is_empty(stack)) {
    int x;
    int y;
    int op;

    stack_pop(stack, &x);
    if (stack_is_empty(stack)) {
      *result = x;
      break;
    }
    
    stack_pop(stack, &y);
    stack_pop(stack, &op);
    stack_push(stack, run_operation(op, y, x));
  }
  
  return 0;
}  
      

int main(int argc, char* argv[]) {
  int result;
  assert(evaluate_polish("-*+129+23", &result) == 0);
  assert(result == 22);

  if (argc != 2) {
    fprintf(stderr, "Wrong usage: %s <polish-expression>\n", argv[0]);
    exit(-1);
  }

  if (evaluate_polish(argv[1], &result) != 0) {
    fprintf(stderr, "Wrong expression: %s\n", argv[1]);
  } else {
    printf("%d\n", result);
  }
  
  return 0;
}
