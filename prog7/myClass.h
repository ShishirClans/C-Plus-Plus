#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
using namespace std;

class myClass {
private:
    int value;

public:
    myClass();        // Default constructor
    myClass(int val);            // Standard constructor
    myClass(const myClass &other);    // Copy constructor
    myClass &operator=(const myClass &other);  // Assignment operator
    ~myClass();      // Destructor

    int getValue() const;
};
#endif
