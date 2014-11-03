struct Point2d;
struct Polygon2d;

void displayPoint(Point2d);
void displayPointPointer(Point2d *);
void BuildPoint(Point2d &);
void BuildPointPointer(Point2d *);

Polygon2d BuildPolygon();
void DisplayPolygon(Polygon2d);

Point2d* GetElement(Polygon2d, int);
