#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class myQueue {
public:
    myQueue();
    void operator+(T item);  // Enqueue
    T operator-();           // Dequeue
    bool isempty();

protected:
    vector<T> elts;
};

#endif
