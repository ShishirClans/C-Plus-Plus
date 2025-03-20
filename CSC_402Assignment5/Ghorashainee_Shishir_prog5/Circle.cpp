#include "Circle.h"

Circle::Circle()
    : Shape(), centerX(0), centerY(0), radius(0.0) {}

Circle::Circle(int cx, int cy, float r, string c, int x, int y, bool hL, int lw, string lc, string ft)
    : Shape(c, x, y, hL, lw, lc, ft), centerX(cx), centerY(cy), radius(r) {}

float Circle::getArea() const {
    return M_PI * radius * radius;
}

float Circle::getCircumference() const {
    return 2 * M_PI * radius;
}

void Circle::printInfo() const {
    cout << "CIRCLE\n";
    cout << "CENTER POSITION: " << centerX << " , " << centerY << endl;
    cout << "RADIUS: " << radius << "  AREA: " << getArea() << endl;
    cout << "CIRCUMFERENCE: " << getCircumference() << endl;
    Shape::printInfo();
}
