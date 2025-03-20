#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "Cuboid.h"
using namespace std;

int main() {
    vector<Shape*> allShapes;
    string filename;
    cout << "Enter path for input file: ";
    cin >> filename;

    ifstream inf(filename);
    if (!inf) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string type;
    while (inf >> type) {
        string color, lineColor, fillType;
        int screenPositionX, screenPositionY, lineWidth;
        bool hasLines;
        inf >> color >> screenPositionX >> screenPositionY >> hasLines >> lineWidth >> lineColor >> fillType;
        Shape* shptr = nullptr;

        if (type == "C" || type == "S") {
            int centerX, centerY;
            float radius;
            inf >> centerX >> centerY >> radius;

            if (type == "C") {
                shptr = new Circle(centerX, centerY, radius, color, screenPositionX, screenPositionY, hasLines, lineWidth, lineColor, fillType);
            } else {
                int centerZ;
                inf >> centerZ;
                shptr = new Sphere(centerZ, centerX, centerY, radius, color, screenPositionX, screenPositionY, hasLines, lineWidth, lineColor, fillType);
            }
        } else if (type == "R" || type == "B") {
            int topLeftX, topLeftY, height, width;
            inf >> topLeftX >> topLeftY >> height >> width;

            if (type == "R") {
                shptr = new Rectangle(topLeftX, topLeftY, height, width, color, screenPositionX, screenPositionY, hasLines, lineWidth, lineColor, fillType);
            } else {
                int topLeftZ, length;
                inf >> topLeftZ >> length;
                shptr = new Cuboid(topLeftZ, length, topLeftX, topLeftY, height, width, color, screenPositionX, screenPositionY, hasLines, lineWidth, lineColor, fillType);
            }
        } else if (type == "T") {
            int pt1X, pt1Y, pt2X, pt2Y, pt3X, pt3Y;
            inf >> pt1X >> pt1Y >> pt2X >> pt2Y >> pt3X >> pt3Y;
            shptr = new Triangle(pt1X, pt1Y, pt2X, pt2Y, pt3X, pt3Y, color, screenPositionX, screenPositionY, hasLines, lineWidth, lineColor, fillType);
        }
        if (shptr) {
            allShapes.push_back(shptr);
        }
    }
    inf.close();
    for (const auto& shape : allShapes) {
        shape->printInfo();
        cout << endl << endl;
    }

    for (auto shape : allShapes) {
        delete shape;
    }
    return 0;
}
