#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float accBalance) {
        accountNumber = accNum;
        balance = accBalance;
    }

    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNum, float accBalance, float accInterestRate) : Account(accNum, accBalance) {
        interestRate = accInterestRate;
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNum, float accBalance, float accOverdraftLimit) : Account(accNum, accBalance) {
        overdraftLimit = accOverdraftLimit;
    }

    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    int accountNumber;
    float balance, interestRate, overdraftLimit;

    cout << "Enter savings account number: ";
    cin >> accountNumber;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter interest rate: ";
    cin >> interestRate;

    SavingsAccount savings(accountNumber, balance, interestRate);

    cout << "\nEnter checking account number: ";
    cin >> accountNumber;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter overdraft limit: ";
    cin >> overdraftLimit;

    CheckingAccount checking(accountNumber, balance, overdraftLimit);

    cout << "\nSavings Account Details:\n";
    savings.displayDetails();

    cout << "\nChecking Account Details:\n";
    checking.displayDetails();

    return 0;
}
