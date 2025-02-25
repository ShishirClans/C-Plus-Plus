

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string firstName, lastName, socsecnum, deptNum;
    double wage;

public:
    Employee();
    Employee(string fName, string lName, string ssn, string dept, double w);
    
    string getFirstName() const;
    string getLastName() const;
    string getSocSecNum() const;
    string getDeptNum() const;
    double getWage() const;
    
    void setFirstName(string fName);
    void setLastName(string lName);
    void setSocSecNum(string ssn);
    void setDeptNum(string dept);
    void setWage(double w);
    
    bool operator<(const Employee &other) const;
    friend ostream &operator<<(ostream &out, const Employee &E);
};

