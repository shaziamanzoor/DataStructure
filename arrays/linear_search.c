#include <stdio.h>
#include <stdbool.h>

bool linear_search(int arr[], int size, int x){
  bool match_found = false;
  
  for(int i = 0; i < size; i++){
    if(arr[i] == x){
      match_found = true;
      break;
    }
  }

  return match_found;
}

int main(){
  int elements[] = {2, 3, 4, 6, 8, 9};
  int size = sizeof elements / sizeof elements[0]; 
 
  assert(linear_search(elements, size, 4) == true);
  assert(linear_search(elements, size, 1) == false);
  return 0;
}
  
