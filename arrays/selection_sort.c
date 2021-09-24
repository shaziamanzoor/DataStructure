#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
void selection_sort(int arr[], int size){
  for(int i = 0; i < size; i++){
    int min_index = i;
    for(int j = i + 1; j < size; j++){
      if (arr[min_index] > arr[j])
        min_index = j;
    }

    int temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
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
  int sorted [] = {1, 0, 2, 3, 4, 7};
  
  size_t size = sizeof  arr / sizeof arr[0]; 
  selection_sort(arr, size);
  assert(array_equals(arr, sorted, size));

  return 0;
}
