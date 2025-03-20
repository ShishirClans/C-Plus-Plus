#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <cmath>

class Triangle : public Shape {
protected:
    int pt1X, pt1Y;
    int pt2X, pt2Y;
    int pt3X, pt3Y;

public:
    Triangle();
    Triangle(int, int, int, int, int, int, string, int, int, bool, int, string, string);

    virtual float getArea() const;
    float getPerimeter() const;
    virtual void printInfo() const override;

private:
    float getDistance(int, int, int, int) const;
};

#endif // TRIANGLE_H
