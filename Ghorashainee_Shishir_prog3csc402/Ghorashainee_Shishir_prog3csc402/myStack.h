// myStack.h
#ifndef MYSTACK_H
#define MYSTACK_H

#include "Employee.h"
#include <vector>
using namespace std;

class myStack {
private:
    vector<Employee> elts;

public:
    vector<Employee>& getElts();
    void Push(Employee);
    Employee Pop();
    bool isempty();
    void printStack();
    myStack operator+(const myStack& other);
};

#endif
