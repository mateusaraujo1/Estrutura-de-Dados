#include <stdio.h>
#include "Point2d.h"

int main() {
	Point2d *a, *b;
	
	a = Point2d_alloc(1.5, 2.3);
	b = Point2d_alloc(5.0, 6.8);
	
	printf("a_x = %f\n", Point2d_getX(a));
	printf("a_y = %f\n", Point2d_getY(a));
	
	printf("b_x = %f\n", Point2d_getX(b));
	printf("b_y = %f\n", Point2d_getY(b));
	
	Point2d_setX(a, 1.7);
	printf("a_x = %f\n", Point2d_getX(a));
	
	printf("distancia = %f\n", Point2d_distance(a, b));
	return 0;
}
