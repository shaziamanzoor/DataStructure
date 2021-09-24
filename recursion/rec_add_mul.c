#include <stdio.h>
#include <assert.h>

int array_sum(int arr[], int begin, int end){
  if (begin >= end) return 0;
  else return arr[begin] + array_sum(arr, begin + 1, end);
}

int find_mul(int arr[], int begin,  int size){
  if (size == 0) return 1;
  return arr[begin] * find_mul(arr, begin + 1, size - 1);
  }

int main(){
  int arr[] = {2, 3, 4, 5, 6};
  int size = sizeof arr/ sizeof arr[0];
  assert(array_sum(arr, 0, size) ==  20);
  assert(find_mul(arr, 0, size) == 720);
}
