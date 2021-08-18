#include <assert.h>
//
// A program to find the fibonacci number at a particular index
//

int fib_recursive(int n) {
  assert(n >= 0);
  if (n == 1 || n == 0) {
    return n;
  } else {
    return fib_recursive(n - 1) + fib_recursive(n - 2);
  }
}

int main(void){
  assert(fib_recursive(5) == 120);
  assert(fib_recursive(4) == 24);
  return 0;
}

  
