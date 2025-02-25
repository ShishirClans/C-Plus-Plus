
// myStack.cpp
#include "myStack.h"

vector<Employee>& myStack::getElts() { return elts; }

void myStack::Push(Employee emp) { elts.push_back(emp); }

Employee myStack::Pop() {
    if (elts.empty()) throw runtime_error("Stack is empty");
    Employee top = elts.back();
    elts.pop_back();
    return top;
}

bool myStack::isempty() { return elts.empty(); }

void myStack::printStack() {
    for (auto it = elts.rbegin(); it != elts.rend(); ++it) {
        cout << *it << endl;
    }
}

myStack myStack::operator+(const myStack& other) {
    myStack temp;
    for (auto it = elts.rbegin(); it != elts.rend(); ++it) temp.Push(*it);
    for (auto& emp : other.elts) temp.Push(emp);
    return temp;
}