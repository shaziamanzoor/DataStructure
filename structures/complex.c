#include <stdio.h>

struct complex{
  double real;
  double imag;
}Complex;

void print_complex(struct complex c){
  printf("%0.2lf + j%0.2lf\n", c.real, c.imag);
}

struct complex add(struct complex a, struct complex b){
  struct complex c;
  c.real = a.real + b.real;
  c.imag = a.imag + b.imag;
  return c;
}
  
int main(void){
  struct complex a = {10, 20};
  struct complex b = {1, 2};
  struct complex c = add(a, b);
  print_complex(c);

  return 0;
}
