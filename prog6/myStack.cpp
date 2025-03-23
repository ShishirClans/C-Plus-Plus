#include "myStack.h"
#include "Employee.h"
#include <stdexcept>

template <typename T>
myStack<T>::myStack() {
    // Default constructor
}

template <typename T>
void myStack<T>::operator+(T item) {
    elts.push_back(item); // Add item to the stack
}

template <typename T>
T myStack<T>::operator-() {
    if (!elts.empty()) {
        T topItem = elts.back();
        elts.pop_back(); // Remove top item
        return topItem;
    }
    throw out_of_range("Stack is empty!");
}

template <typename T>
bool myStack<T>::isempty() {
    return elts.empty();
}

// Explicit template instantiations
template class myStack<int>;
template class myStack<string>;
template class myStack<double>;
template class myStack<Employee>;  // Now Employee is recognized
