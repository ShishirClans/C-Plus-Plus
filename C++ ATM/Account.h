#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
protected:
    std::string accountID;
    std::string accountPIN;
    double accountBalance;

public:
    // Default Constructor
    Account();

    // Parameterized Constructor
    Account(std::string id, std::string pin, double balance);

    // Getters
    std::string getID() const;
    std::string getPIN() const;
    double getBalance() const;

    // Setters
    void setID(std::string id);
    void setPIN(std::string pin);
    void setBalance(double balance);

    // Additional Methods
    void printBalance() const;
    void Deposit(double amt);
    void Withdraw(double amt);
};

#endif
