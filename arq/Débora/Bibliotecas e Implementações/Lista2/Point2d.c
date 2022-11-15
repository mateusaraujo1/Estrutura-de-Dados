#include "biblioteca/Point2d.h"
#include <stdlib.h>
#include <math.h>

struct Point2d{
  float x;
  float y;
};

Point2d *Point2d_create(float a, float b){
  Point2d *ptr = malloc(sizeof(Point2d));
  ptr->x = a;
  ptr->y = b;
  return ptr;
}

void Point2d_delete(Point2d *ptr){
  free(ptr);
  ptr = NULL;
}

float Point2d_distance(Point2d *ptr1, Point2d *ptr2){
  return sqrt(pow(ptr2->x - ptr1->x, 2) + pow(ptr2->y - ptr1->y , 2));
}

float Point2d_perimetro(Point2d *a, Point2d *b, Point2d *c){
  return Point2d_distance(a, b) + Point2d_distance(c, b) + Point2d_distance(a, c);
}
