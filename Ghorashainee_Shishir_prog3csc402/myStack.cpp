#include "myStack.h"

// Getter to access the elements vector
vector<Employee>& myStack::getElts() {
    return elts;
}

// Push function to add an Employee to the top of the stack
void myStack::Push(const Employee& emp1) {
    elts.push_back(emp1);
}

// Pop function to remove the top element and return it
Employee myStack::Pop() {
    if (!isempty()) {
        Employee top = elts.back(); // Get the top element
        elts.pop_back(); // Remove the top element
        return top; // Return the removed element
    }
    throw runtime_error("Stack is empty!"); // Handle empty stack case
}

// Check if the stack is empty
bool myStack::isempty() const {
    return elts.empty();
}

// Print the stack from top to bottom
void myStack::printStack() const {
    for (int i = elts.size() - 1; i >= 0; --i) {
        cout << elts[i] << endl; // Use overloaded << operator to print Employee
    }
}

// Overloaded + operator to combine two stacks
myStack myStack::operator+(const myStack& other) {
    myStack temp;

    // Reverse copy of S1 (this stack) into temp stack
    for (int i = elts.size() - 1; i >= 0; --i) {
        temp.Push(elts[i]);
    }

    // Push items from S2 (other stack) onto temp stack
    for (int i = other.elts.size() - 1; i >= 0; --i) {
        temp.Push(other.elts[i]);
    }

    return temp;
}
