#include "Employee.h"

// Default constructor
Employee::Employee() : firstName(""), lastName(""), salary("") {}

// Parameterized constructor
Employee::Employee(string first, string last, string sal)
    : firstName(first), lastName(last), salary(sal) {}

// Overloaded operator<< to output Employee data
ostream &operator<<(ostream &out, const Employee &E) {
    out << E.firstName << " " << E.lastName << " " << E.salary;  // Output the salary as a string
    return out;
}

// Overloaded operator>> to input Employee data
istream &operator>>(istream &in, Employee &E) {
    // Read the full line for each employee (first name, last name, and salary)
    in >> E.firstName >> E.lastName >> E.salary;  // This will correctly read all parts from the same line
    return in;
}
