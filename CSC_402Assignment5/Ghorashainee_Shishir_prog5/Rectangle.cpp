#include "Rectangle.h"

Rectangle::Rectangle()
    : Shape(), topLeftX(0), topLeftY(0), height(0), width(0) {}

Rectangle::Rectangle(int x, int y, int h, int w, string c, int spX, int spY, bool hL, int lw, string lc, string ft)
    : Shape(c, spX, spY, hL, lw, lc, ft), topLeftX(x), topLeftY(y), height(h), width(w) {}

float Rectangle::getArea() const {
    return width * height;
}

float Rectangle::getPerimeter() const {
    return 2 * (height + width);
}

void Rectangle::printInfo() const {
    cout << "RECTANGLE\n";
    cout << "TOP LEFT: " << topLeftX << " , " << topLeftY << endl;
    cout << "HEIGHT: " << height << endl;
    cout << "WIDTH: " << width << endl;
    cout << "AREA: " << getArea() << endl;
    cout << "PERIMETER: " << getPerimeter() << endl;
    Shape::printInfo();
}
