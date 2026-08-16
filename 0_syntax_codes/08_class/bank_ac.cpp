#include <iostream>
using namespace std;

class BankAccount {
private:
    long long accountNumber;
    double balance;

public:
    // Parameterized Constructor
    BankAccount(long long accNo, double initBalance) {
        accountNumber = accNo;
        balance = initBalance;
        cout << "Constructor: Account " << accountNumber << " initialized with $" << balance << endl;
    }

    // Member function to deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }

    // Member function to display balance
    void displayBalance() const {
        cout << "Account No: " << accountNumber << " | Current Balance: $" << balance << endl;
    }

    // Destructor
    ~BankAccount() {
        cout << "Destructor: Account " << accountNumber << " memory released." << endl;
    }
};

int main() {
    // 1. Dynamic object creation using 'new'
    BankAccount* acc = new BankAccount(987654321, 1000.0);

    // 2. Performing operations
    acc->deposit(500.0);
    acc->displayBalance();

    // 3. Releasing memory using 'delete'
    delete acc;

    return 0;
}
