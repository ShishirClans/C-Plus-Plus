#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;
    int screenPositionX;
    int screenPositionY;
    bool hasLines;
    int lineWidth;
    string lineColor;
    string fillType;

public:
    Shape();
    Shape(string, int, int, bool, int, string, string);
    virtual ~Shape() = default;
    virtual void printInfo() const;
};

#endif // SHAPE_H
