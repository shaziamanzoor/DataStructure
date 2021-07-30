#include <stdio.h>

int addElements(int *ptr, int size){                                         
  int total = 0;
  for(int i = 0; i < size; i++){
    total = total + ptr[i];
  }
  return total;
}


int main(){
  int arr[] = {2, 4, 6, 8};
  int size = sizeof arr / sizeof arr[0];
  int total = 0;
  total = addElements(arr, size);
  printf("The sum of array = %d \n", total);
  return 0;
}
  
   
  

               
