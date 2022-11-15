#include <stdio.h>
#include "biblioteca/Point2d.h"

int main(){
  Point2d *p1 = Point2d_create(-3, -11);
  Point2d *p2 = Point2d_create(2, 1);
  Point2d *p3 = Point2d_create(1, -11);
  printf("perimetro = %f\n", Point2d_perimetro(p1, p2, p3));
  Point2d_delete(p1);
  Point2d_delete(p2);
  Point2d_delete(p3);
  return 0;
}
