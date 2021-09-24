#include <stdio.h>
#include <stdlib.h>

#define BUFFER_TO_STRING 20

struct point{
  int x;
  int y;
};

// {10, 20} -> "Point(10, 20)"
char* to_string(struct point* ptr) {
  char* buffer = malloc(sizeof(char) * BUFFER_TO_STRING);
  snprintf(buffer, BUFFER_TO_STRING, "Point(%d, %d)", ptr->x, ptr->y);
  return buffer;
}


int main(void){
  struct point Point = {10, 30};;
  struct point *sp = &Point;
  char* str_point = to_string(sp);
  printf("%s\n", str_point);
  free(str_point);
  return 0;
}
