/*Shishir Ghorashainee
 *CSC 402
 * Feb 3rd, 2025
 * Prof. Gary Newell
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>  // For malloc



using namespace std;

// Function declarations
void processData(ifstream& inf, vector<int>& CPPstack, int* Cstack, int size);
void push(int* stack, int size, int& numelts, int value);
void pop(int* stack, int& numelts);
void top(const int* stack, int numelts);
void printStack(const vector<int>& CPPstack, const int* Cstack, int numelts);

void multiplyStacks(vector<int>& CPPstack, int* Cstack, int numelts, int value);


// Main function
int main() {
    // Declare a string to hold the path to the input file
    string filepath;
    cout << "Enter the path to the input file: " << endl; // Prompt the user to enter the path to the input file
    cin >> filepath;

    // Declare ifstream variable to read the file
    ifstream inf(filepath); // Open the file
    if (!inf.is_open()) { // Check if the file was opened successfully
        cerr << "Error: Could not open file." << endl; // Print an error message
        return 1;  // Exit with error code
    }

    // Read the size of the Cstack array from the first line of the input file
    int size;// Declare a variable to hold the size of the Cstack
    inf >> size; // Read the size from the input file

    // Allocate space for Cstack using malloc
    int* Cstack = (int*) malloc(size * sizeof(int)); // Allocate memory for the Cstack

    // Declare an empty vector for CPPstack
    vector<int> CPPstack; // Declare a vector to hold the CPPstack

    // Process the input data
    processData(inf, CPPstack, Cstack, size); // Process the data from the input file

    // Free the allocated memory
    free(Cstack); // Free the memory allocated for the Cstack

    return 0; // Exit successfully
}

// Function to process data from the input file
void processData(ifstream& inf, vector<int>& CPPstack, int* Cstack, int size) { // Process the data from the input file
    string command; // Declare a string to hold the command
    int value; // Declare an integer to hold the value
    int numelts = 0;  // Keep track of the number of elements in Cstack

    while (inf >> command >> value) { // Read the command and value from the input file
        if (command == "PUSH") { // Check if the command is PUSH
            // Push onto the CPPstack
            CPPstack.push_back(value);

            // Push onto the Cstack
            push(Cstack, size, numelts, value);
        }
        else if (command == "POP") { // Check if the command is POP
            // Pop from the CPPstack
            if (!CPPstack.empty()) { // Check if the CPPstack is not empty
                CPPstack.pop_back(); // Pop from the CPPstack
            } else {
                cout << "NO POP - STACK IS EMPTY" << endl; // Print an error message
            }

            // Pop from the Cstack
            pop(Cstack, numelts); // Pop from the Cstack
        }
        else if (command == "TOP") { // Check if the command is TOP
            // Print the top of the CPPstack
            if (!CPPstack.empty()) {
                cout << CPPstack.back() << endl; // Print the top of the CPPstack
            } else {
                cout << "NO TOP" << endl; // Print an error message
            }

            // Print the top of the Cstack
            top(Cstack, numelts);
        }



        else if (command == "MUL") {
            multiplyStacks(CPPstack, Cstack, numelts, value);
        }



    }

    // print both stacks after processing
    printStack(CPPstack, Cstack, numelts); // Print the CPPstack and Cstack
}

// Function to push an element onto the Cstack
void push(int* stack, int size, int& numelts, int value) { // Push a value onto the Cstack
    if (numelts < size) {
        stack[numelts++] = value; // Push the value onto the Cstack
    } else {
        cout << "NO PUSH - STACK IS FULL" << endl; // Print an error message
    }
}

// Function to pop an element from the Cstack
void pop(int* stack, int& numelts) { // Pop a value from the Cstack
    if (numelts > 0) { // Check if the Cstack is not empty
        numelts--; // Decrement the number of elements
    } else {
        cout << "NO POP - STACK IS EMPTY" << endl; // Print an error message
    }
}

// Function to print the top of the Cstack
void top(const int* stack, int numelts) { // Print the top of the Cstack
    if (numelts > 0) { // Check if the Cstack is not empty
        cout << stack[numelts - 1] << endl; // Print the top of the Cstack
    } else {  // If the Cstack is empty
        cout << "NO TOP" << endl; // Print an error message
    }
}

// Function to print the stacks
void printStack(const vector<int>& CPPstack, const int* Cstack, int numelts) { // Print the CPPstack and Cstack
    // Print the CPPstack
    cout << "CPPSTACK:" << endl;
    if (CPPstack.empty()) { // Check if the CPPstack is empty
        cout << "STACK IS EMPTY" << endl; // Print an error message
    } else { // If the CPPstack is not empty
        for (int i = CPPstack.size() - 1; i >= 0; --i) { // Print the CPPstack from top to bottom
            cout << CPPstack[i] << endl; // Print the value
        }
    }

    // Print the Cstack
    cout << "CSTACK:" << endl;
    if (numelts == 0) { // Check if the Cstack is empty
        cout << "STACK IS EMPTY" << endl; // Print an error message
    } else { // If the Cstack is not empty
        for (int i = numelts - 1; i >= 0; --i) { // Print the Cstack from top to bottom
            cout << Cstack[i] << endl; // Print the value
        }
    }
}



void multiplyStacks(vector<int>& CPPstack, int* Cstack, int numelts, int value) {
    // Multiply each element in the CPPstack
    for (int& num : CPPstack) {
        num *= value;
    }

    // Multiply each element in the Cstack
    for (int i = 0; i < numelts; ++i) {
        Cstack[i] *= value;
    }
}




//Output:
/*
Enter the path to the input file:
C:\Users\shish\Desktop\C++\input_1.txt
5
5
CPPSTACK:
4
3
2
1
CSTACK:
4
3
2
1

--------------------------------------------------------

Enter the path to the input file:
C:\Users\shish\Desktop\C++\input_2.txt
NO PUSH - STACK IS FULL
NO PUSH - STACK IS FULL
CPPSTACK:
5
4
3
2
1
CSTACK:
3
2
1

--------------------------------------------------------

Enter the path to the input file:
C:\Users\shish\Desktop\C++\input_3.txt
7
7
12
12
NO TOP
NO TOP
NO POP - STACK IS EMPTY
NO POP - STACK IS EMPTY
CPPSTACK:
STACK IS EMPTY
CSTACK:
STACK IS EMPTY

--------------------------------------------------------

Enter the path to the input file:
C:\Users\shish\Desktop\C++\input_4.txt
2
2
4
4
CPPSTACK:
6
8
10
CSTACK:
6
8
10

--------------------------------------------------------


*/
