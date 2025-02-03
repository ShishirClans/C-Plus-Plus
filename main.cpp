//This program reads a sequence of commands from an input file and processes them using a Cstack and a CPPstack.
// The program reads the size of the Cstack from the input file, dynamically allocates memory for the Cstack using malloc,
// and processes the commands from the input file. The program pushes values onto the Cstack and CPPstack, pops values from the
// Cstack and CPPstack, and prints the top of the Cstack and CPPstack. The program also prints the contents of the Cstack
// and CPPstack at the end of the input file.


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
    }

    // After processing, print both stacks
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
    cout << "CPPSTACK (top to bottom):" << endl;
    if (CPPstack.empty()) { // Check if the CPPstack is empty
        cout << "STACK IS EMPTY" << endl; // Print an error message
    } else { // If the CPPstack is not empty
        for (int i = CPPstack.size() - 1; i >= 0; --i) { // Print the CPPstack from top to bottom
            cout << CPPstack[i] << endl; // Print the value
        }
    }

    // Print the Cstack
    cout << "Cstack contents (top to bottom):" << endl;
    if (numelts == 0) { // Check if the Cstack is empty
        cout << "STACK IS EMPTY" << endl; // Print an error message
    } else { // If the Cstack is not empty
        for (int i = numelts - 1; i >= 0; --i) { // Print the Cstack from top to bottom
            cout << Cstack[i] << endl; // Print the value
        }
    }
}



//Output:

/*
 * Output for t1.in:
5
5
CPPstack contents (top to bottom):
4
3
2
1
Cstack contents (top to bottom):
4
3
2
1

Process finished with exit code 0

 *Output for t2.in:
 **NO PUSH - STACK IS FULL
NO PUSH - STACK IS FULL
CPPstack contents (top to bottom):
5
4
3
2
1
Cstack contents (top to bottom):
3
2
1

Process finished with exit code 0

 Output for t3.in:

7
7
12
12
NO TOP
NO TOP
NO POP – STACK IS EMPTY
NO POP – STACK IS EMPTY
CPPstack contents (top to bottom):
STACK IS EMPTY
Cstack contents (top to bottom):
STACK IS EMPTY

Process finished with exit code 0
*/