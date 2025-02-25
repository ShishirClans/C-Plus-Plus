// myQueue.h
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "Employee.h"
#include <vector>
using namespace std;

class myQueue {
private:
    vector<Employee> elts;

public:
    vector<Employee>& getElts();
    void Enqueue(Employee);
    Employee Dequeue();
    bool isempty();
    void printQueue();
    myQueue operator+(const myQueue& other);
};

#endif