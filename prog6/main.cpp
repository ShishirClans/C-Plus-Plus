#include "myQueue.h"
#include "myStack.h"
#include "Employee.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    myQueue<int> intQueue;
    myQueue<string> stringQueue;
    myQueue<string> doubleQueue; // Store doubles as strings
    myQueue<Employee> employeeQueue;

    myStack<int> intStack;
    myStack<string> stringStack;
    myStack<string> doubleStack; // Store doubles as strings
    myStack<Employee> employeeStack;

    string filename;
    cout << "Enter input file name: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Reading and enqueuing integers
    int numInts;
    infile >> numInts;
    for (int i = 0; i < numInts; ++i) {
        int value;
        infile >> value;
        intQueue + value;
    }

    // Reading and enqueuing strings
    int numStrings;
    infile >> numStrings;
    for (int i = 0; i < numStrings; ++i) {
        string value;
        infile >> value;
        stringQueue + value;
    }

    // Reading and enqueuing doubles (as strings)
    int numDoubles;
    infile >> numDoubles;
    infile.ignore();  // Ignore any newline character before reading the next value
    for (int i = 0; i < numDoubles; ++i) {
        string value;
        getline(infile, value); // Read full line to preserve format
        doubleQueue + value;
    }

    // Reading and enqueuing Employees
    int numEmployees;
    infile >> numEmployees;
    infile.ignore();
    for (int i = 0; i < numEmployees; ++i) {
        Employee emp;
        infile >> emp;
        employeeQueue + emp;
    }

    infile.close();  // Close input file

    // Printing Queue Output
    cout << "\n#### QUEUE OUTPUT ####\n\nQueued Integers\n\n";
    while (!intQueue.isempty()) cout << (-intQueue) << "\n";

    cout << "\nQueued Strings\n\n";
    while (!stringQueue.isempty()) cout << (-stringQueue) << "\n";

    cout << "\nQueued Doubles\n\n";
    while (!doubleQueue.isempty()) {
        cout << (-doubleQueue) << "\n";  // Directly print the string
    }

    cout << "\nQueued Employees\n\n";
    while (!employeeQueue.isempty()) cout << (-employeeQueue) << "\n";

    // === STACK PROCESSING ===
    infile.open(filename);
    if (!infile) {
        cerr << "Error reopening file!" << endl;
        return 1;
    }

    // Reading and pushing integers onto stack
    infile >> numInts;
    for (int i = 0; i < numInts; ++i) {
        int value;
        infile >> value;
        intStack + value;
    }

    // Reading and pushing strings onto stack
    infile >> numStrings;
    for (int i = 0; i < numStrings; ++i) {
        string value;
        infile >> value;
        stringStack + value;
    }

    // Reading and pushing doubles onto stack (as strings)
    infile >> numDoubles;
    infile.ignore();
    for (int i = 0; i < numDoubles; ++i) {
        string value;
        getline(infile, value); // Read as string
        doubleStack + value;
    }

    // Reading and pushing Employees onto stack
    infile >> numEmployees;
    infile.ignore();
    for (int i = 0; i < numEmployees; ++i) {
        Employee emp;
        infile >> emp;
        employeeStack + emp;
    }

    infile.close();  // Close input file again

    // Printing Stack Output
    cout << "\n**** STACK OUTPUT ****\n\nStacked Integers\n\n";
    while (!intStack.isempty()) cout << (-intStack) << "\n";

    cout << "\nStacked Strings\n\n";
    while (!stringStack.isempty()) cout << (-stringStack) << "\n";

    cout << "\nStacked Doubles\n\n";
    while (!doubleStack.isempty()) {
        cout << (-doubleStack) << "\n";  // Directly print the string
    }

    cout << "\nStacked Employees\n\n";
    while (!employeeStack.isempty()) {
        cout << (-employeeStack) << "\n";  // Directly print the string representation of the Employee
    }

    cout << "\nEND OF EXECUTION\n";

    return 0;
}
