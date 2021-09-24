#include <stdio.h>

struct point{
  int x;
  int y;
};
int main(void){
  struct point Point = {20, 30};;
  struct point *sp = &Point;

  printf("Point = {%d, %d}\n", sp->x, sp->y);
  return 0;
 
}
