#include <math.h>
#include <stdlib.h>
#include "Point2d.h"

struct Point2d{
	float x, y;
};

Point2d *Point2d_alloc(float x, float y) {
	Point2d *p = malloc(sizeof(Point2d));
	if (p) {
		p->x = x;
		p->y = y;
	}
	return p;
}

void Point2d_free(Point2d *p) {
	if (p)
		free(p);
}

float Point2d_getX(Point2d *p) {
	if (p)
		return p->x;
	return 0;
}

float Point2d_getY(Point2d *p) {
	if (p)
		return p->y;
	return 0;
}

void Point2d_setX(Point2d *p, float x) {
	if (p)
		p->x = x;
}

void Point2d_setY(Point2d *p, float y) {
	if (p)
		p->y = y;
}

float Point2d_distance(Point2d *p1, Point2d *p2) {
	if (p1 && p2) {
		return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
	}
	return 0;
}
