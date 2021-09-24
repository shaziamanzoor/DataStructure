// tail recursion (optional)                                                                             
int fib_iterative_helper(int n, int a, int b);                                                           
                                                                                                         
int fib_iterative(int n) {                                                                               
  return fib_iterative_helper(n, 0, 1);                                                                  
}                                                                                                        
                                                                                                         
int fib_iterative_helper(int n, int a, int b) {                                                          
  if (n == 0) {                                                                                          
    return a;                                                                                            
  } else {                                                                                               
    return fib_iterative_helper(n - 1, b, a + b);                                                        
  }                                                                                                      
}                                                                                                        
             
