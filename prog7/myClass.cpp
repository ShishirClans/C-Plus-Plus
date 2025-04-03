#include "myClass.h"

myClass::myClass(int val) : value(val) {
    cout << "STANDARD CONSTRUCTOR EXECUTING" << endl;
}

myClass::myClass(const myClass &other) : value(other.value) {
    cout << "COPY Constructor EXECUTING NOW" << endl;
}

myClass::myClass() : value(0) {
    cout << "DEFAULT CONSTRUCTOR EXECUTING" << endl;
}

myClass &myClass::operator=(const myClass &other) {
    if (this != &other) {
        value = other.value;
        cout << "ASSIGNMENT OPERATOR EXECUTING" << endl;
        myClass temp(other);
    }
    return *this;
}

myClass::~myClass() {
    cout << "DESTRUCTOR EXECUTING" << endl;
}

int myClass::getValue() const {
    return value;
}
