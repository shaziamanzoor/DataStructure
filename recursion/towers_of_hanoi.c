#include <stdio.h>

void move_last(int disk, char from, char to) {
  printf("Move disk# %d from %c to %c\n", disk, from, to);
}

void move(int n, char from, char to, char pivot) {
  if (n == 0) return;

  move(n - 1, from, pivot, to);
  move_last(n, from, to);
  move(n - 1, pivot, to, from);
}

int main(void) {
  move(1, 'A', 'B', 'C');
  printf("\n\n");
  move(2, 'A', 'B', 'C');
  printf("\n\n");
  move(3, 'A', 'B', 'C');
  return 0;
}
