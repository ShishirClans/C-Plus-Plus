#ifndef PROGRAM4_ORDEREDSET_H
#define PROGRAM4_ORDEREDSET_H

#include "mySet.h"
#include <algorithm> // For the sort function
#include <ostream>

// OrderedSet: Inherits from mySet and keeps elements in sorted order
class OrderedSet : public mySet {
public:
    OrderedSet() = default;      // Default constructor
    OrderedSet(const mySet &S);    // Converts mySet to OrderedSet

    OrderedSet Union(const OrderedSet &OS) const;          // Union operation
    OrderedSet Intersection(const OrderedSet &OS) const;   // Intersection operation
    OrderedSet Difference(const OrderedSet &OS) const;     // Difference operation

    bool addelt(int x);  // Adds element and keeps set sorted
    void SortSet();       // Sorts elements in ascending order

    friend ostream& operator<<(ostream &ost, const OrderedSet &OS); // Output display
};
#endif // PROGRAM4_ORDEREDSET_H
