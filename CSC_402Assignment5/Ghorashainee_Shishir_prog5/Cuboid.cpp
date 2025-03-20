#include "Cuboid.h"

Cuboid::Cuboid()
    : Rectangle(), topLeftZ(0), length(0) {}

Cuboid::Cuboid(int z, int l, int x, int y, int h, int w, string c, int spX, int spY, bool hL, int lw, string lc, string ft)
    : Rectangle(x, y, h, w, c, spX, spY, hL, lw, lc, ft), topLeftZ(z), length(l) {}

float Cuboid::getArea() const {
    return 2 * (length * width + length * height + width * height);
}

float Cuboid::getVolume() const {
    return length * width * height;
}

void Cuboid::printInfo() const {
    cout << "CUBOID\n";
    cout << "TOP LEFT POSITION: " << topLeftX << " , " << topLeftY << " , " << topLeftZ << endl;
    cout << "HEIGHT: " << height << endl;
    cout << "WIDTH: " << width << endl;
    cout << "LENGTH: " << length << endl;
    cout << "SURFACE AREA: " << getArea() << endl;
    cout << "VOLUME: " << getVolume() << endl;
    Shape::printInfo();
}
