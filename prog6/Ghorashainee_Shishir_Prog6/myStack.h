#ifndef MYSTACK_H
#define MYSTACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class myStack {
public:
    myStack();
    void operator+(T item); // Push
    T operator-();          // Pop
    bool isempty();

protected:
    vector<T> elts;
};

#endif
