#include "Sphere.h"

Sphere::Sphere()
    : Circle(), centerZ(0) {}

Sphere::Sphere(int cz, int cx, int cy, float r, string c, int x, int y, bool hL, int lw, string lc, string ft)
    : Circle(cx, cy, r, c, x, y, hL, lw, lc, ft), centerZ(cz) {}

float Sphere::getArea() const {
    return 4 * M_PI * radius * radius;
}

float Sphere::getVolume() const {
    return (4.0 / 3) * M_PI * radius * radius * radius;
}

void Sphere::printInfo() const {
    cout << "SPHERE\n";
    cout << "CENTER POSITION: " << centerX << " , " << centerY << " , " << centerZ << endl;
    cout << "RADIUS: " << radius << "  SURFACE AREA: " << getArea() << endl;
    cout << "VOLUME: " << getVolume() << endl;
    Shape::printInfo();
}
