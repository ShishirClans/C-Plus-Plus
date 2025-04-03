#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "exceptions.h"
#include "myClass.h"

using namespace std;

void verifyPassword(string proposedPassword) {
    if (proposedPassword.size() < 10) {
        throw MinimumLengthException();
    }
    for (char c : proposedPassword) {
        if (isspace(c)) {
            throw ContainsWhitespaceException();
        }
    }
    if (none_of(proposedPassword.begin(), proposedPassword.end(), ::isdigit)) {
        throw NoDigitsException();
    }
    if (none_of(proposedPassword.begin(), proposedPassword.end(), ::isupper)) {
        throw NoUppercaseException();
    }
}

int main() {
    bool validPassword;
    string password;
    cout << "\nPART A OUTPUT" << "\n\n";
    do {
        validPassword = true;
        cout << "Please enter new password : ";
        getline(cin, password);

        try {
            verifyPassword(password);
        } catch (const runtime_error &e) {
            cout << e.what() << endl;
            validPassword = false;
        } catch (...) {
            cout << "Unknown error occurred!" << endl;
            validPassword = false;
        }
    } while (!validPassword);

    cout << "\n**** PASSWORD VERIFIED AND ACCEPTED ****\n" << endl;

    cout << "\nPART B OUTPUT" << "\n\n";
    myClass A(55);
    myClass B(A);
    myClass C, D(B);
    C = B;

    cout << "\nA value is " << A.getValue() << endl;
    cout << "B value is " << B.getValue() << endl;
    cout << "C value is " << C.getValue() << endl;
    cout << "D value is " << D.getValue() << endl;

    cout << "\nPreparing to call destructors for D, C, B, and A" << endl;

    return 0;  // Ensures destructors are called
}
