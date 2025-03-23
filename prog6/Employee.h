#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    Employee();
    Employee(string first, string last, string sal);  // Change salary to string

    friend ostream &operator<<(ostream &out, const Employee &E);
    friend istream &operator>>(istream &in, Employee &E);

protected:
    string firstName;
    string lastName;
    string salary;  // Change salary to string to preserve the format
};

#endif
