#include "sort.h"
#include <stdio.h>

#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
#define PARENT(i) ((i - 1)/2)

void swap(int a[], int i, int j){
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int find_better_child(int a[], int end, int index) {
  if (LEFT(index) < end && a[LEFT(index)] < a[RIGHT(index)])
    return RIGHT(index);
  else
    return LEFT(index);
}

void insert(int a[], int end) {
  int i = end;
  int item = a[end];
  int parent = PARENT(i);
  while (i > 0 && a[parent] > item) {
    a[i] = a[parent];
    i = parent;
    parent = PARENT(i);
  }

  a[i] = item;
}

void adjust(int a[], int end, int index) {
  int item = a[index];
  while (index < end) {
    int better_child = find_better_child(a, end, index);
    if (item <= a[better_child]) break;
    a[index] = a[better_child];
    index = better_child;
  }
  
  a[index] = item;
}

void heapify(int a[], int end) {
  for (int i = end/2; i >= 0; i--)
    adjust(a, end, i);
}

void heapsort(int a[], int size) {
  heapify(a, size - 1);
  for (int i = size - 1; i >= 1; i--) {
   swap(a, i, 0);
   adjust(a, 1, i - 1);
  }
}

