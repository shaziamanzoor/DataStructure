#include <stdio.h>

struct point{
  int x;
  int y;
} ;


struct rect{
  struct point top_left;
  struct point bottom_right;
};

struct point make_point(int x, int y){
  struct point p;
  p.x = x;
  p.y = y;
  return p;
}

// addpoint is a function taking two structures and returning a structure.
struct point addpoint(struct point top_left, struct point bottom_right){
  top_left.x += bottom_right.x;
  top_left.y += bottom_right.y;
  return top_left;
}

void working_with_points(){
  // Initializing a structure
  struct point a = {2, 3};

  // Creating a structure at runtime
  struct point b = make_point(20, 30);

  // Passing and returning structures.
  struct point c = addpoint(a, b);
  printf("(%d, %d) = (%d, %d) + (%d, %d)\n",
         c.x, c.y, a.x, a.y, b.x, b.y);
}


int main(void){
  struct point a = {10, 20};
  printf("a.x = %d,  a.y = %d\n\n", a.x , a.y);

  
  struct rect screen = {{1, 2}, {3, 4}};
  printf("screen.top_left.x = %d, screen.top_left.y = %d \n" 
         "screen.bottom_right.x = %d, screen.bottom_right.y = %d\n",
          screen.top_left.x, screen.top_left.y,
          screen.bottom_right.x, screen.bottom_right.y);
  printf("\n");

  working_with_points();
  
  return 0;
}
