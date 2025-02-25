// myQueue.cpp
#include "myQueue.h"

vector<Employee>& myQueue::getElts() { return elts; }

void myQueue::Enqueue(Employee emp) { elts.push_back(emp); }

Employee myQueue::Dequeue() {
    if (elts.empty()) throw runtime_error("Queue is empty");
    Employee front = elts.front();
    elts.erase(elts.begin());
    return front;
}

bool myQueue::isempty() { return elts.empty(); }

void myQueue::printQueue() {
    for (const auto& emp : elts) cout << emp << endl;
}

myQueue myQueue::operator+(const myQueue& other) {
    myQueue temp = *this;
    for (const auto& emp : other.elts) temp.Enqueue(emp);
    return temp;
}