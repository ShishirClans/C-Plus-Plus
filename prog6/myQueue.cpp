#include "myQueue.h"
#include "Employee.h"
#include <stdexcept>

template <typename T>
myQueue<T>::myQueue() {
    // Default constructor
}

template <typename T>
void myQueue<T>::operator+(T item) {
    elts.push_back(item); // Add item to the queue
}

template <typename T>
T myQueue<T>::operator-() {
    if (!elts.empty()) {
        T frontItem = elts.front();
        elts.erase(elts.begin()); // Remove front item
        return frontItem;
    }
    throw out_of_range("Queue is empty!");
}

template <typename T>
bool myQueue<T>::isempty() {
    return elts.empty();
}

// Explicit template instantiations
template class myQueue<int>;
template class myQueue<string>;
template class myQueue<double>;
template class myQueue<Employee>;  // Now Employee is recognized
