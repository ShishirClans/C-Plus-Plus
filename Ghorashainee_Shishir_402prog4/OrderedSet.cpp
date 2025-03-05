#include "OrderedSet.h"

OrderedSet::OrderedSet(const mySet &S) {
    elts = S.getelts();
    size = S.getsize();
    SortSet();
}

OrderedSet OrderedSet::Union(const OrderedSet &OS) const {
    mySet ms = mySet::Union(OS);
    OrderedSet temp(ms);
    temp.SortSet();
    return temp;
}

OrderedSet OrderedSet::Intersection(const OrderedSet &OS) const {
    mySet ms = mySet::Intersection(OS);
    OrderedSet temp(ms);  // Convert intersection result to OrderedSet
    temp.SortSet();
    return temp;
}

OrderedSet OrderedSet::Difference(const OrderedSet &OS) const {
    mySet ms = mySet::Difference(OS);
    OrderedSet temp(ms);  // Convert difference result to OrderedSet
    temp.SortSet();
    return temp;
}

bool OrderedSet::addelt(int x) {
    bool result = mySet::addelt(x);
    if (result) SortSet();  // Sort after adding if successful
    return result;
}

void OrderedSet::SortSet() {
    sort(elts.begin(), elts.end());
}
ostream& operator<<(ostream &ost, const OrderedSet &OS) {
    ost << "{ ";
    for (size_t i = 0; i < OS.elts.size(); ++i) {
        ost << OS.elts[i];
        if ((i + 1) % 10 == 0 && i < OS.elts.size() - 1) ost << "\n";
        else if (i < OS.elts.size() - 1) ost << ", ";
    }
    ost << " }";
    return ost;
}
