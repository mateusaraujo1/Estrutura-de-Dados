typedef struct Point2d Point2d;

Point2d *Point2d_create(float, float);
void Point2d_delete(Point2d *);
float Point2d_distance(Point2d *, Point2d *);
float Point2d_perimetro(Point2d *, Point2d *, Point2d *);
