#ifndef PROGRAM4_MYSET_H
#define PROGRAM4_MYSET_H

#include <vector>
#include <iostream>
using namespace std;

class mySet {
protected:
    vector<int> elts;
    int size;

public:
    mySet();  // Default constructor

    bool isempty() const;
    bool isfound(int x) const;
    bool addelt(int x);
    bool deleteelt(int x);

    const vector<int>& getelts() const;
    int getsize() const;

    mySet Union(const mySet &S) const;
    mySet Intersection(const mySet &S) const;
    mySet Difference(const mySet &S) const;

    friend ostream& operator<<(ostream &ost, const mySet &S); // Overload for output
    bool operator==(const mySet &other) const;                // Checks equality of two sets
};

#endif
