#include "mySet.h"
#include <algorithm>

mySet::mySet() : size(0) {} // Initializes an empty set

bool mySet::isempty() const {
    return size == 0;
}

bool mySet::isfound(int x) const {
    return find(elts.begin(), elts.end(), x) != elts.end(); // Checks for x in the set
}

bool mySet::addelt(int x) {
    if (!isfound(x)) { // Adds x if not present
        elts.push_back(x);
        ++size;
        return true;
    }
    return false;
}

bool mySet::deleteelt(int x) {
    auto it = find(elts.begin(), elts.end(), x);
    if (it != elts.end()) { // Removes x if it's foundd
        elts.erase(it);
        --size;
        return true;
    }
    return false;
}

const vector<int>& mySet::getelts() const{
    return elts;
}

int mySet::getsize() const {
    return size;
}

mySet mySet::Union(const mySet &S) const {
    mySet temp = *this; // Starts with a copy of this set
    for (int x : S.elts) {
        temp.addelt(x); // Adds unique elements from S
    }
    return temp;
}

mySet mySet::Intersection(const mySet &S) const {
    mySet temp;
    for (int x : elts) {
        if (S.isfound(x)) temp.addelt(x);
    }
    return temp;
}

mySet mySet::Difference(const mySet &S) const {
    mySet temp;
    for (int x : elts) {
        if (!S.isfound(x)) temp.addelt(x);
    }
    return temp;
}

ostream& operator<<(ostream &ost, const mySet &S) {
    ost << "{ ";
    for (size_t i = 0; i < S.elts.size(); ++i) {
        ost << S.elts[i];
        if ((i + 1) % 10 == 0 && i < S.elts.size() - 1) ost << "\n";
        else if (i < S.elts.size() - 1) ost << ", ";
    }
    ost << " }";
    return ost;
}

bool mySet::operator==(const mySet &other) const {
    if (size != other.size) return false;
    for (int x : elts) {
        if (!other.isfound(x)) return false;
    }
    return true;
}
