
#ifndef PROGRAM3_MYSTACK_H
#define PROGRAM3_MYSTACK_H

#include <vector>
#include "Employee.h"
#include <iostream>
using namespace std;

class myStack {
private:
    vector<Employee> elts; // Stack implemented using a vector of Employee objects

public:
    // Getter function to return the vector of elements by reference
    vector<Employee>& getElts();

    // Push function to add an Employee to the top of the stack
    void Push(const Employee& emp1);

    // Pop function to remove and return the top Employee from the stack
    Employee Pop();

    // Check if the stack is empty
    bool isempty() const;

    // Print the stack starting from the top (non-destructive)
    void printStack() const;

    // Overloaded + operator to add two stacks
    myStack operator+(const myStack& other);

};

#endif //PROGRAM3_MYSTACK_H
