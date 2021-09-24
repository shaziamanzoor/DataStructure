#include <stdio.h>
int count_down(int n);
int main(void){
  int n = 5;
  count_down(n);
}
int count_down(int n){
  if(n <= 0){
    printf("Count down completed \n");
    return 0;
  }
  printf("%d \n", n);
  count_down(n - 1);
  return 0;
}
