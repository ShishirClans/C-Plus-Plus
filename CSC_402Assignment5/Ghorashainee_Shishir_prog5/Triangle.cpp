#include "Triangle.h"

Triangle::Triangle()
    : Shape(), pt1X(0), pt1Y(0), pt2X(0), pt2Y(0), pt3X(0), pt3Y(0) {}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, string c, int x, int y, bool hL, int lw, string lc, string ft)
    : Shape(c, x, y, hL, lw, lc, ft), pt1X(x1), pt1Y(y1), pt2X(x2), pt2Y(y2), pt3X(x3), pt3Y(y3) {}

float Triangle::getDistance(int x1, int y1, int x2, int y2) const {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float Triangle::getArea() const {
    return 0.5 * abs(pt1X * (pt2Y - pt3Y) + pt2X * (pt3Y - pt1Y) + pt3X * (pt1Y - pt2Y));
}

float Triangle::getPerimeter() const {
    return getDistance(pt1X, pt1Y, pt2X, pt2Y) +
           getDistance(pt2X, pt2Y, pt3X, pt3Y) +
           getDistance(pt3X, pt3Y, pt1X, pt1Y);
}

void Triangle::printInfo() const {
    cout << "TRIANGLE\n";
    cout << "POINT 1: " << pt1X << " , " << pt1Y << endl;
    cout << "POINT 2: " << pt2X << " , " << pt2Y << endl;
    cout << "POINT 3: " << pt3X << " , " << pt3Y << endl;
    cout << "AREA: " << getArea() << endl;
    cout << "PERIMETER: " << getPerimeter() << endl;
    Shape::printInfo();
}
