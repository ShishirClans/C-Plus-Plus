// Employee.cpp
#include "Employee.h"

Employee::Employee() : firstName(""), lastName(""), socsecnum(""), deptNum(""), wage(0.0) {}

Employee::Employee(string lName, string fName, string ssn, string dept, double w)
    : lastName(lName),firstName(fName), socsecnum(ssn), deptNum(dept), wage(w) {}

string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }
string Employee::getSocSecNum() const { return socsecnum; }
string Employee::getDeptNum() const { return deptNum; }
double Employee::getWage() const { return wage; }

void Employee::setFirstName(string fName) { firstName = fName; }
void Employee::setLastName(string lName) { lastName = lName; }
void Employee::setSocSecNum(string ssn) { socsecnum = ssn; }
void Employee::setDeptNum(string dept) { deptNum = dept; }
void Employee::setWage(double w) { wage = w; }

bool Employee::operator<(const Employee &other) const {
    return deptNum < other.deptNum || (deptNum == other.deptNum && (lastName < other.lastName || (lastName == other.lastName && firstName < other.firstName)));
}

ostream &operator<<(ostream &out, const Employee &E) {
    out << E.lastName << " " << E.firstName << " " << E.socsecnum << " " << E.deptNum << " " << E.wage;
    return out;
}