#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void insertion_sort(int arr[], size_t size){
  for(int i = 1; i < size; i++){
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

bool array_equals(int xs[], int ys[], size_t size){
  int equal = true;
  for(int i = 0; i < size; i++){
    if(xs[i] != ys[i]){
      equal = false;
      break;
    }
  }
  return equal;
}

void print_array(int xs[], size_t size) {
  for (int i = 0; i < size; i++) 
    printf(" %d", xs[i]);
  printf("\n");
}

int main(){
  int arr[] = {3, 1, 4, 0, 6};
  int sorted [] = {0, 1, 3, 4, 6};
  
  int arr2[] = {9, 2, 7, 8};
  
  int sorted2 [] = {2, 7, 8, 9};
  
  int size = sizeof arr / sizeof arr[0];
  int size2 = sizeof arr2 / sizeof arr2[0];

  insertion_sort(arr, size);
  print_array(arr, size);
  assert(array_equals(arr, sorted, size));
  
  insertion_sort(arr2, size2);
  print_array(arr2, size2);
  assert(array_equals(arr2, sorted2, size2));

  int two_arr[] = {2, 1};
  int a1[] = {1, 2};

  insertion_sort(two_arr, 2);
  print_array(two_arr, 2);
  assert(array_equals(two_arr, a1, 2));
  return 0;
}
