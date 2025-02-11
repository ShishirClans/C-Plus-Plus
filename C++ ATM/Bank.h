#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>
#include <fstream>

class Bank {
protected:
    std::vector<Account> allAccounts;
    Account dummyAccount;

public:
    // Default Constructor
    Bank();

    // Find Account
    Account &findAcct(std::string id, std::string pin);

    // Add Account
    void addAcct(Account &acct);

    // Load Accounts from File
    void loadAccounts(std::ifstream &inf);
};

#endif
