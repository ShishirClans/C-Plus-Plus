/*
// main.cpp
#include "Employee.h"
#include "myStack.h"
#include "myQueue.h"
#include <fstream>

int main() {
    myStack S1, S2, S3;
    myQueue Q1, Q2, Q3;
    string fileName;

    cout << "Enter first file path: ";
    cin >> fileName;
    ifstream file1(fileName);
    if (!file1) {
        cerr << "Error opening file.";
        return 1;
    }

    string first, last, ssn, dept;
    double wage;
    while (file1 >> last >> first >> ssn >> dept >> wage) {
        Employee emp(first, last, ssn, dept, wage);
        S1.Push(emp);
        Q1.Enqueue(emp);
    }
    file1.close();

    cout << "Enter second file path: ";
    cin >> fileName;
    ifstream file2(fileName);
    if (!file2) {
        cerr << "Error opening file.";
        return 1;
    }

    while (file2 >> last >> first >> ssn >> dept >> wage) {
        Employee emp(first, last, ssn, dept, wage);
        S2.Push(emp);
        Q2.Enqueue(emp);
    }
    file2.close();

    S3 = S1 + S2;
    Q3 = Q1 + Q2;

    S3.printStack();
    Q3.printQueue();

    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Employee.h"
#include "myStack.h"
#include "myQueue.h"

using namespace std;

int main() {
    // Declare Stack and Queue objects for the first, second, and third sets
    myStack S1, S2, S3;
    myQueue Q1, Q2, Q3;

    // Get file path for the first input file
    string filePath;
    cout << "Please enter a path for file #1: ";
    cin >> filePath;

    // Open the first input file
    ifstream inFile1(filePath);
    if (!inFile1) {
        cerr << "Error opening file: " << filePath << endl;
        return 1;
    }

    string lastName, firstName, socsecnum, deptNum;
    double wage;

    // Read data from the first file and populate stacks and queues
    while (inFile1 >> lastName >> firstName >> socsecnum >> deptNum >> wage) {
        Employee emp1(lastName, firstName, socsecnum, deptNum, wage);
        Employee emp2(lastName, firstName, socsecnum, deptNum, wage); // Create another Employee object for the queue

        S1.Push(emp1); // Push to stack
        Q1.Enqueue(emp2); // Enqueue to queue
    }
    inFile1.close();

    // Get file path for the second input file
    cout << "Please enter a path for file #2: ";
    cin >> filePath;

    // Open the second input file
    ifstream inFile2(filePath);
    if (!inFile2) {
        cerr << "Error opening file: " << filePath << endl;
        return 1; // Exit if the file can't be opened
    }

    // Read data from the second file and populate stacks and queues
    while (inFile2 >> lastName >> firstName >> socsecnum >> deptNum >> wage) {
        Employee emp1(lastName, firstName, socsecnum, deptNum, wage);
        Employee emp2(lastName, firstName, socsecnum, deptNum, wage); // Create another Employee object for the queue

        S2.Push(emp1); // Push to stack
        Q2.Enqueue(emp2); // Enqueue to queue
    }
    inFile2.close();

    // Print all stacks and queues before sorting
    cout << "\nStack #1 " << endl;
    cout << "______" << endl;
    S1.printStack();

    cout << "\nQueue #1 " << endl;
    cout << "______" << endl;
    Q1.printQueue();

    cout << "\nStack #2 " << endl;
    cout << "______" << endl;
    S2.printStack();

    cout << "\nQueue #2 " << endl;
    cout << "______" << endl;
    Q2.printQueue();

    // Sort the stacks and queues
    sort(S1.getElts().begin(), S1.getElts().end(), less<Employee>());
    sort(S2.getElts().begin(), S2.getElts().end(), less<Employee>());
    sort(Q1.getElts().begin(), Q1.getElts().end(), less<Employee>());
    sort(Q2.getElts().begin(), Q2.getElts().end(), less<Employee>());

    // Print sorted stacks and queues
    cout << "\nAFTER SORTING ALL VECTORS" << endl;
    cout << "\nSTACK #1" << endl;
    cout << "______" << endl;
    S1.printStack();

    cout << "\nQUEUE #1" << endl;
    cout << "______" << endl;
    Q1.printQueue();

    cout << "\nSTACK #2" << endl;
    cout << "______" << endl;
    S2.printStack();

    cout << "\nQUEUE #2" << endl;
    cout << "______" << endl;
    Q2.printQueue();

    // Combine stacks and queues using overloaded operator
    S3 = S1 + S2;
    Q3 = Q1 + Q2;

    cout << "\nAfter overloaded operator +" << endl;
    // Print combined stacks and queues
    cout << "\nStack #3" << endl;
    cout << "______" << endl;
    S3.printStack();

    cout << "\nQueue #3" << endl;
    cout << "______" << endl;
    Q3.printQueue();

    // Sort the overloaded stack and queue
    sort(S3.getElts().begin(), S3.getElts().end(), less<Employee>());
    sort(Q3.getElts().begin(), Q3.getElts().end(), less<Employee>());

    cout << "\nAfter SORTING" << endl;
    // Print sorted combined stack and queue
    cout << "\nStack #3" << endl;
    cout << "______" << endl;
    S3.printStack();

    cout << "\nQueue #3" << endl;
    cout << "______" << endl;
    Q3.printQueue();

    // Pop all items from stack S2
    cout << "\nREMOVING ALL ITEMS FROM S2 and Q2" << endl;

    cout << "\nItems POPPED from Stack S2" << endl;
    while (!S2.isempty()) {
        try {
            Employee emp = S2.Pop();
            cout << "\nPOPPING " << emp << endl;
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
    }

    // Attempt to pop from the empty stack to trigger the error message
    try {
        S2.Pop();
    } catch (const runtime_error& e) {
        cout << "\nERROR - STACK IS EMPTY" << endl;
    }

    // Dequeue all elements from queue Q2
    cout << "\nItems DEQUEUED from Queue Q2" << endl;
    while (!Q2.isempty()) {
        try {
            Employee emp = Q2.Dequeue();
            cout << "\nDEQUEUEING " << emp << endl;
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
        }
    }

    // Attempt to dequeue from the empty queue to trigger the error message
    try {
        Q2.Dequeue();
    } catch (const runtime_error& e) {
        cout << "\nERROR - QUEUE IS EMPTY" << endl;
    }

    // Print exit message
    cout << "\nPROGRAM EXECUTION IS COMPLETE" << endl;

    return 0; // Exit successfully
}
