//
// A program to compute factorial of a number.
//
#include <assert.h>
// Recursive
int fact_recursive(int n) {
  assert(n > 0);
  if (n == 1) {
    return 1;
  } else {
    // Delegate to your copy
    int result = fact_recursive(n - 1);

    // Do your thing.
    return n * result; // n * fact_recursive(n - 1);
  }
}


//optional tail recursion
int fact_iterative_helper(int n, int result);

int fact_iterative(int n) {
  return fact_iterative_helper(n, 1);
}

int fact_iterative_helper(int n, int result) {
  assert(n > 0);
  if (n == 1) {
    return result;
  } else {
    return fact_iterative_helper(n - 1, result * n);
  }
}

  
int main(void){
  int n = 3;
  int n1 = 4;
  int n2 = 5;
  assert(fact_recursive(n) == 6);
  assert(fact_recursive(n1) == 24);
  assert(fact_recursive(n2)== 120);
  assert(fact_iterative_helper(n) == 6);
  assert(fact_iterative_helper(n1) == 24);
  assert(fact_iterative_helper(n2) == 120);    
  return 0;
}
    
  
