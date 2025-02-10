#include "ATM.h"
#include <fstream>
using namespace std;
int main() {
    ifstream inf;
    string filename;

    cout << "Enter path for account information: ";
    cin >> filename;
    inf.open(filename);

    if (!inf) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    Bank bk;
    bk.loadAccounts(inf);
    inf.close();

    ATM atm(bk);
    int result = atm.start();

    if (result == 1)
        cout << "Account not found - system shutting down\n";
    else
        cout << "Normal Exit\n";

    return 0;
}
