#include <stdio.h>
#include <assert.h>

int findIndex(int *ptr ,int size, int num){
  for(int i = 0; i < size; i++){
    if(ptr[i] == num)
      return i;
  }
  return -1;
}

int main(){
  int arr[] = {1,2,3,4,5}; // an array of positive integers.
  
  int size = sizeof arr / sizeof arr[0];
  int num = 5;
  
  int result = findIndex(arr,size,num);
  printf("The index  of %d is %d\n",num,result);
   assert(findIndex(arr, 4, 2) == 1);
   assert(findIndex(arr, 4, 3) == 2);
   assert(findIndex(arr, 4, 2) == 3);
  

  
  return 0;
}

  


