#include "Bank.h"
#include <iostream>
using namespace std;

// Default Constructor
Bank::Bank() : dummyAccount() {}

// Find Account
Account &Bank::findAcct(string id, string pin) {
    for (auto &acct : allAccounts) {
        if (acct.getID() == id && acct.getPIN() == pin) {
            return acct;
        }
    }
    return dummyAccount;
}

// Add Account
void Bank::addAcct(Account &acct) {
    allAccounts.push_back(acct);
}

// Load Accounts from File
void Bank::loadAccounts(ifstream &inf) {
    string id, pin;
    double balance;

    while (inf >> id >> pin >> balance) {
        Account newAcct(id, pin, balance);
        addAcct(newAcct);
    }
}
