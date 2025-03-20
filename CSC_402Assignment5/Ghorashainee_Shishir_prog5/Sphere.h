#ifndef SPHERE_H
#define SPHERE_H

#include "Circle.h"

class Sphere : public Circle {
protected:
    int centerZ;

public:
    Sphere();
    Sphere(int, int, int, float, string, int, int, bool, int, string, string);

    virtual float getArea() const override;
    float getVolume() const;
    virtual void printInfo() const override;
};

#endif // SPHERE_H
