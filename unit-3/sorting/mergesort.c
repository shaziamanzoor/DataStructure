#include "sort.h"
#include <stdio.h>

static void copy(int dest[], int source[], int from, int to) {
  while (from <= to) {
    dest[from] = source[from];
    from++;
  }
}

static void merge(int a[], int aux[], int low, int mid, int high) {
  copy(aux, a, low, high);
  int i = low;
  int j = mid + 1;
  for (int k = low; k <= high; k++) {
    if (i > mid)
      a[k] = aux[j++];
    else if (j > high)
      a[k] = aux[i++];
    else if (aux[i] < aux[j])
      a[k] = aux[i++];
    else
      a[k] = aux[j++];
  }
}

static void _mergesort(int a[], int aux[], int low, int high) {
  if (low >= high) return;
  
  int mid = (low + high) / 2;
  _mergesort(a, aux, low, mid);
  _mergesort(a, aux, mid + 1, high);
  merge(a, aux, low, mid, high);
}

void mergesort(int a[], int size) {
  int aux[size];
  _mergesort(a, aux, 0, size - 1);
}
