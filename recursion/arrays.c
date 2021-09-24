#include <stdio.h>
#include <assert.h>

int array_sum(int arr[], int begin, int end){
  if (begin >= end) return 0;
  else return arr[begin] + array_sum(arr, begin + 1, end);
}

int array_multiply(int arr[], int begin,  int end){
  if (begin >= end) return 1;
  return arr[begin] * array_multiply(arr, begin + 1, end);
}
 
int main(){
  int arr[] = {2, 3, 4, 5, 6};
  int arr2[] = {2, 2, 2, 2};
  int arr3[] = {5, 6, 2};
  int arr_size = sizeof arr/ sizeof arr[0];
  int arr2_size = sizeof arr2 / sizeof arr2[0];
  
  assert(array_sum(arr, 0, arr_size) ==  20);
  assert(array_multiply(arr, 0, arr_size) == 720);
  assert(array_multiply(arr2, 0, arr2_size) == 16);
  assert(array_multiply(arr3, 0 , 3) == 160);
}
