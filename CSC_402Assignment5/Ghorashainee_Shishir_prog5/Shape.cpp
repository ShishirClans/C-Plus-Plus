#include "Shape.h"

Shape::Shape()
    : color("Transparent"), screenPositionX(0), screenPositionY(0),
      hasLines(false), lineWidth(0), lineColor("BLACK"), fillType("NONE") {}

Shape::Shape(string c, int x, int y, bool hL, int lw, string lc, string ft)
    : color(c), screenPositionX(x), screenPositionY(y),
      hasLines(hL), lineWidth(lw), lineColor(lc), fillType(ft) {}

void Shape::printInfo() const {
    cout << "SHAPE INFO\n";
    cout << "POSITION: " << screenPositionX << " , " << screenPositionY << endl;
    cout << "Color: " << color << endl;
    cout << (hasLines ? "Has Lines" : "No Lines") << endl;
    cout << "Line Width: " << lineWidth << "  Line Color: " << lineColor << endl;
    cout << "Fill type: " << fillType << endl;
}
