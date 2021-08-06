#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int binary_search(int arr[], int low, int high, int target){
  if (low < high) {
    int mid = (low + high) / 2;
    int midValue = arr[mid];

    if (target == midValue) {
      return mid;
    } else if (target < midValue) {
      return binary_search(arr, low, mid, target);
    } else {
      return binary_search(arr, mid + 1, high, target);
    }
  }

  return -1;
}


int main(){
  int elements[] = {2, 3, 4, 6, 8, 9, 34, 90, 112, 221};
  int length = sizeof elements/sizeof elements[0]; 

  assert(binary_search(elements, 0, length, 0) == -1);
  assert(binary_search(elements, 0, length, 222) == -1);
  assert(binary_search(elements, 0, length, 5) == -1);
  
  assert(binary_search(elements, 0, length, 4) == 2);
  assert(binary_search(elements, 0, length, 2) == 0);
  assert(binary_search(elements, 0, length, 221) == 9);
  
  return 0;
}
  
