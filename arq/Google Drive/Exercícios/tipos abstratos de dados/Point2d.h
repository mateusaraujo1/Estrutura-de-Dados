typedef struct Point2d Point2d;

Point2d *Point2d_alloc(float x, float y);
void Point2d_free(Point2d *p);

float Point2d_getX(Point2d *p);
float Point2d_getY(Point2d *p);

void Point2d_setX(Point2d *p, float x);
void Point2d_setY(Point2d *p, float y);

float Point2d_distance(Point2d *p1, Point2d *p2);
