#include <stdio.h>
#include "biblioteca/Point2d.h"

int main(){
  Point2d *p1, *p2;
  p1 = Point2d_create(1, -11);
  p2 = Point2d_create(2, 1);
  printf("Distancia  = %f\n", Point2d_distance(p1, p2));
  Point2d_delete(p1);
  Point2d_delete(p2);
  return 0;
}
