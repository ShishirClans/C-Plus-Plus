#ifndef ATM_H
#define ATM_H

#include "Bank.h"

class ATM {
private:
    Bank &bank;

public:
    // Constructor
    ATM(Bank &b);

    // Start ATM
    int start();

    // Transactions Menu
    void transactions(Account &acct);
};

#endif
