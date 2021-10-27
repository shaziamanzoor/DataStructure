#include <stdbool.h>
#include "sort.h"

static void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

static int partition(int a[], int low, int high) {
  int i = low;
  int j = high + 1;
  int v = a[low];

  while (true) {
    while (a[++i] < v) 
      if (i == high) break;

    while (a[--j] >= v)
      if (j == low) break;

    if (i >= j) break;
    swap(a, i, j);
  }

  swap(a, low, j);
  return j;
}

static void _sort(int a[], int low, int high) {
  if (low < high) {
    int p = partition(a, low, high);
    _sort(a, low, p - 1);
    _sort(a, p + 1, high);
  }
}

void quicksort(int a[], int size) {
  _sort(a, 0, size - 1);
}
