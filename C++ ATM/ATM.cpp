#include "ATM.h"
#include <iostream>

using namespace std;

ATM::ATM(Bank &bk) : bank(bk) {}

int ATM::start() {
    char command;

    while (true) {
        cout << "Please enter your command:\nQ - quit/exit\nL - login to account\n";
        cin >> command;
        command = toupper(command);

        if (command == 'Q') {
            return 0;
        } else if (command == 'L') {
            string id, pin;
            int attempts = 0;
            while (attempts < 3) {
                cout << "Enter Account ID: ";
                cin >> id;
                cout << "Enter PIN: ";
                cin >> pin;

                Account &acct = bank.findAcct(id, pin);
                if (acct.getID() != "") {
                    transactions(acct);
                    break;
                } else {
                    cout << "Invalid credentials. Try again.\n";
                    attempts++;
                }
            }
            if (attempts == 3) {
                cout << "Account not found - system shutting down\n";
                return 1;
            }
        } else {
            cout << "Invalid command! Try again.\n";
        }
    }
}

void ATM::transactions(Account &acct) {
    char selection;

    while (true) {
        cout << "Please enter your selection or Q to quit:\nW - withdraw funds\nD - deposit funds\nB - check balance\nQ - quit/exit\n";
        cin >> selection;
        selection = toupper(selection);

        if (selection == 'Q') {
            break;
        } else if (selection == 'W') {
            double amt;
            cout << "Enter amount to withdraw: ";
            cin >> amt;
            acct.Withdraw(amt);
        } else if (selection == 'D') {
            double amt;
            cout << "Enter amount to deposit: ";
            cin >> amt;
            acct.Deposit(amt);
        } else if (selection == 'B') {
            acct.printBalance();
        } else {
            cout << "Invalid selection! Try again.\n";
        }
    }
}
