#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int binary_search(int arr[], int low, int high, int target){
  int left = low;
  int right = high;
  int result = -1;
  
  while (left < right) {
    int mid = (left + right) / 2;
    int midValue = arr[mid];

    if (target == midValue) {
      result = mid;
      break;
    } else if (target < midValue) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return result;
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
  
