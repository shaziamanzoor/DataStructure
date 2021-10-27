#include <stdio.h>
#include "sort.h"

void print_array(int a[], size_t size) {
  for (int i = 0; i < size; i++) 
    printf("%d, ", a[i]);
  printf("\n");
}


int main(void) {
  int a[] = {9, 6, 18, 2, 7, 4, 26, 11, 6, 10, 3};
  int size = sizeof(a) / sizeof(int);

  quicksort(a, size);
  print_array(a, size);

  int b[] = {7, 4, 1, 9, 4, 8, 3, 6, 10, 2};
  int b_size = sizeof(b) / sizeof(int);

  mergesort(b, b_size);
  print_array(b, b_size);

  int c[] = {6, 2, 7, 3, 4, 1, 8, 9, 11, -5, 19, 12, 4};
  int c_size = sizeof(c) / sizeof(int);

   heapsort(c, c_size);
   print_array(c, c_size);
  return 0;
}
