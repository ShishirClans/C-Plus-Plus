#ifndef CUBOID_H
#define CUBOID_H

#include "Rectangle.h"

class Cuboid : public Rectangle {
protected:
    int topLeftZ;
    int length;

public:
    Cuboid();
    Cuboid(int, int, int, int, int, int, string, int, int, bool, int, string, string);

    virtual float getArea() const override;
    float getVolume() const;
    virtual void printInfo() const override;
};

#endif // CUBOID_H
