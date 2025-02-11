#include "Account.h"
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;
// Default Constructor
Account::Account() : accountID(""), accountPIN(""), accountBalance(0.0) {}

// Parameterized Constructor
Account::Account(string id, string pin, double balance) {
    if (id.length() == 8 && pin.length() == 4 && all_of(pin.begin(), pin.end(), ::isdigit) && balance >= 0.0) {
        accountID = id;
        accountPIN = pin;
        accountBalance = balance;
    } else {
        cerr << "Invalid account data provided!" << endl;
        accountID = "";
        accountPIN = "";
        accountBalance = 0.0;
    }
}

// Getters
string Account::getID() const { return accountID; }
string Account::getPIN() const { return accountPIN; }
double Account::getBalance() const { return accountBalance; }

// Setters
void Account::setID(string id) { accountID = id; }
void Account::setPIN(string pin) { accountPIN = pin; }
void Account::setBalance(double balance) { accountBalance = balance; }

// Print balance
void Account::printBalance() const {
    cout << "Current Balance: $" << accountBalance << endl;
}

// Deposit method
void Account::Deposit(double amt) {
    if (amt >= 0.0) {
        accountBalance += amt;
    } else {
        cerr << "Error: Deposit amount must be non-negative!" << endl;
    }
}

// Withdraw method
void Account::Withdraw(double amt) {
    if (amt > 0.0 && amt <= accountBalance) {
        accountBalance -= amt;
    } else {
        cerr << "Error: Invalid withdrawal amount!" << endl;
    }
}
