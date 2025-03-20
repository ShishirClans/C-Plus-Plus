#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
protected:
    int centerX;
    int centerY;
    float radius;

public:
    Circle();
    Circle(int, int, float, string, int, int, bool, int, string, string);

    virtual float getArea() const;
    float getCircumference() const;
    virtual void printInfo() const override;
};

#endif // CIRCLE_H
