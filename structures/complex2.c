#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 100


typedef struct complex{
  double real;
  double imag;
}Complex;


Complex* new_complex(double real, double imag){
  Complex *c = malloc(sizeof(Complex));
  c->real = real;
  c->imag = imag;
  return c;                    
}

Complex* add(Complex *a, Complex *b){
  return new_complex(a->real + b->real, a->imag + b->imag);
}

int main(void){
  Complex *a;
  Complex *b;

  a = new_complex(10, 20);
  b = new_complex(1, 2);
  Complex *c = add(a, b);
  printf("The result is %0.2lf + j%0.2lf\n", c->real, c->imag);
  
  free(c);
  free(b);
  free(a);

  return 0;
}
