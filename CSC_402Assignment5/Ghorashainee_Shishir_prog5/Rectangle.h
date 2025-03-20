#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
protected:
    int topLeftX;
    int topLeftY;
    int height;
    int width;

public:
    Rectangle();
    Rectangle(int, int, int, int, string, int, int, bool, int, string, string);

    virtual float getArea() const;
    float getPerimeter() const;
    virtual void printInfo() const override;
};

#endif // RECTANGLE_H
