
#include "mySet.h"
#include "OrderedSet.h"
#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

// Function to read integers from a file into a set
void readFileToSet(const string &filename, mySet &set);
void readFileToOrderedSet(const string &filename, OrderedSet &set);
void addIntegersFromFile(const string &filename, mySet &set, const string &setName);
void deleteIntegersFromFile(const string &filename, mySet &set, const string &setName);

int main() {
    // Declare six mySet and six OrderedSet objects
    mySet S1, S2, S3, S4, S5, S6;
    OrderedSet OS1, OS2, OS3, OS4, OS5, OS6;

    // Input first file and populate S1
    string filename;
    cout << "Please enter a path to an input file: ";
    cin >> filename;
    readFileToSet(filename, S1);

    // Input second file and populate S2
    cout << "Please enter a path to a second input file: ";
    cin >> filename;
    cout << endl;
    readFileToSet(filename, S2);

    // Display initial sets
    cout << "BEFORE OPERATIONS\n";
    cout << "\nMySet S1 Contents\n----------------\n" << S1 << endl;
    cout << "\nMySet S2 Contents\n----------------\n" << S2 << endl;
    cout << "\nMySet S3 Contents\n----------------\n";
    if (S3.isempty()) cout << "Set is EMPTY\n";
    else cout << S3 << endl;

    // Perform Union and display S3
    S3 = S1.Union(S2);
    cout << "\nAfter UNION Operation of S1 and S2\nMySet S3 Contents\n----------------\n" << S3 << endl;
    cout << "\nMySet S1 Contents\n----------------\n" << S1 << endl;
    cout << "\nMySet S2 Contents\n----------------\n" << S2 << endl;

    // Perform Intersection and display S4
    S4 = S1.Intersection(S2);
    cout << "\nAfter INTERSECTION Operation of S1 and S2\nMySet S4 Contents\n----------------\n" << S4 << endl;
    cout << "\nMySet S1 Contents\n----------------\n" << S1 << endl;
    cout << "\nMySet S2 Contents\n----------------\n" << S2 << endl;

    // Perform Difference and display S5
    S5 = S1.Difference(S2);
    cout << "\nAfter DIFFERENCE Operation of S1 and S2\n\nMySet S5 Contents\n----------------\n" << S5 << endl;
    cout << "\nMySet S1 Contents\n----------------\n" << S1 << endl;
    cout << "\nMySet S2 Contents\n----------------\n" << S2 << endl;

    // Check equivalence of S3 and S6 (Union of S1 and S3)
    S6 = S1.Union(S3);
    cout << "\nS3 and S6 " << (S3 == S6 ? "ARE" : "ARE NOT") << " EQUAL\n";
    cout << "S1 and S6 " << (S1 == S6 ? "ARE" : "ARE NOT") << " EQUAL\n";

    // Read and add elements from a third file into S1
    cout << "\nPlease enter a path to a third input file:  ";
    cin >> filename;
    cout << endl;
    addIntegersFromFile(filename, S1, "S1");

    cout << "\nS1 AFTER ADDITION of elements\n\nMySet S1 Contents\n----------------\n"<< S1 << endl;

    // Read and delete elements from a fourth file from S1
    cout << "\nPlease enter a path to a fourth input file: ";
    cin >> filename;
    cout << endl;
    deleteIntegersFromFile(filename, S1, "S1");

    cout << "\nS1 AFTER DELETION of elements\n\nMySet S1 Contents\n----------------\n" << S1 << endl;

    cout << endl;
    // Repeat all actions for OrderedSets
    cout << "\nOUTPUT FOR ORDERED SETS\n";
    cout << endl;

    cout << "Please enter a path to an input file:";
    cin >> filename;
    readFileToOrderedSet(filename, OS1);

    cout << "Please enter a path to a second input file: ";
    cin >> filename;
    readFileToOrderedSet(filename, OS2);

    cout << "\nBEFORE OPERATIONS\n";
    cout << "\nOrderedSet OS1 Contents\n----------------\n" << OS1 << endl;
    cout << "\nOrderedSet OS2 Contents\n----------------\n" << OS2 << endl;
    cout << "\nOrderedSet OS3 Contents\n----------------\n";
    if (OS3.isempty()) cout << "Ordered Set is EMPTY\n";
    else cout << OS3 << endl;

    OS3 = OS1.Union(OS2);
    cout << "\nAfter UNION Operation of OS1 and OS2\n\nOrderedSet OS3 Contents\n----------------\n" << OS3 << endl;
    cout << "\nOrderedSet OS1 Contents\n----------------\n" << OS1 << endl;
    cout << "\nOrderedSet OS2 Contents\n----------------\n" << OS2 << endl;

    OS4 = OS1.Intersection(OS2);
    cout << "\nAfter INTERSECTION Operation of OS1 and OS2\n\nOrderedSet OS4 Contents\n----------------\n" << OS4 << endl;
    cout << "\nOrderedSet OS1 Contents\n----------------\n" << OS1 << endl;
    cout << "\nOrderedSet OS2 Contents\n----------------\n" << OS2 << endl;

    OS5 = OS1.Difference(OS2);
    cout << "\nAfter DIFFERENCE Operation of OS1 and OS2\n\nMySet OS5 Contents\n----------------\n" << OS5 << endl;
    cout << "\nMySet OS1 Contents\n----------------\n" << OS1 << endl;
    cout << "\nMySet OS2 Contents\n----------------\n" << OS2 << endl;

    OS6 = OS1.Union(OS3);
    cout << "\nOS3 and OS6 " << (OS3 == OS6 ? "ARE" : "ARE NOT") << " EQUAL\n";
    cout << "OS1 and OS6 " << (OS1 == OS6 ? "ARE" : "ARE NOT") << " EQUAL\n";
    cout << endl;
    cout << "Please enter a path to a third input file: ";
    cin >> filename;
    addIntegersFromFile(filename, OS1, "OS1");
    cout << endl;
    cout << "OS1 AFTER ADDITION of elements\n\nOrderedSet OS1 Contents\n----------------\n" << OS1 << endl;
    cout << endl;

    cout << "Please enter a path to a fourth input file: ";
    cin >> filename;
    cout << endl;

    deleteIntegersFromFile(filename, OS1, "OS1");
    cout << endl;
    cout << "OS1 AFTER DELETION of elements\n\nOrderedSet OS1 Contents\n----------------\n" << OS1 << endl;
    cout << endl;
    cout << "PROGRAM COMPLETE" << endl;
    return 0;
}

// Function implementations
/*
void readFileToSet(const string &filename, mySet &set) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    int number;
    while (infile >> number) {
        set.addelt(number);
    }
    infile.close();
}

void readFileToOrderedSet(const string &filename, OrderedSet &set) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    int number;
    while (infile >> number) {
        set.addelt(number);
    }
    infile.close();
    set.SortSet();
}
*/
void readFileToSet(const string &filename, mySet &set) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    stack<int> tempStack;
    int number;
    while (infile >> number) {
        tempStack.push(number);
    }
    infile.close();

    while (!tempStack.empty()) {
        set.addelt(tempStack.top());
        tempStack.pop();
    }
}

void readFileToOrderedSet(const string &filename, OrderedSet &set) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    stack<int> tempStack;
    int number;
    while (infile >> number) {
        tempStack.push(number);
    }
    infile.close();

    while (!tempStack.empty()) {
        set.addelt(tempStack.top());
        tempStack.pop();
    }
    set.SortSet(); // Ensures OrderedSet remains sorted
}





void addIntegersFromFile(const string &filename, mySet &set, const string &setName) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    int number;
    while (infile >> number) {
        if (set.addelt(number)) {
            cout << number << " was successfully added to " << setName << endl;
        } else {
            cout << number << " ALREADY PRESENT IN " << setName << endl;
        }
    }
    infile.close();
}

void deleteIntegersFromFile(const string &filename, mySet &set, const string &setName) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    int number;
    while (infile >> number) {
        if (set.deleteelt(number)) {
            cout << number << " was successfully deleted from "<< setName << endl;
        } else {
            cout << number << " NOT FOUND " << endl;
        }
    }
    infile.close();
}
