#include <stdbool.h>                                                                      
#include <stdio.h>                                                                        
#include <assert.h>

int find_min_index(int arr[], size_t size, int start) {
  int min_index = start;
  for(int j = start + 1; j < size; j++) {
    if (arr[min_index] > arr[j])                                                      
      min_index = j;                                                                    
  }

  return min_index;
}

void swap(int arr[], int i, int j) {  
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void selection_sort(int arr[], size_t size){
  for(int i = 0; i < size; i++){
    int min_index = find_min_index(arr, size, i);
    swap(arr, min_index, i);
  }        
}

bool array_equals(int xs[], int ys[], size_t size){
  bool equal = true;
  
  for(int i = 0; i < size; i++){    
    if(xs[i] != ys[i]){
       equal = false;
       break;
    }
  }
    return equal;  
}

int main(){
  int arr[] = {1, 2, 3, 4, 7, 0};
  int sorted [] = {0, 1, 2, 3, 4, 7};
  
  size_t size = sizeof  arr / sizeof arr[0]; 
  selection_sort(arr, size);
  assert(array_equals(arr, sorted, size));

  return 0;
}
