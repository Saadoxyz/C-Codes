#include <iostream>
using namespace std;
class BankAccount {
private:
    int accountID;
    double balance;
public:
    BankAccount(int id, double bal) : accountID(id), balance(bal) {}
    void balance_inquiry() {
        cout << "Account ID: " << getAccountID() << ", Balance: Rs. " << getBalance() << endl;
    }
    void withdraw_amount(double amount) {
        if (getBalance() >= amount) {
            setBalance(getBalance() - amount);
            cout << "Withdrawal of Rs. " << amount << " successful. Remaining balance: Rs. " << getBalance() << endl;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }
    void deposit_amount(double amount) {
        setBalance(getBalance() + amount);
        cout << "Deposit of Rs. " << amount << " successful. New balance: Rs. " << getBalance() << endl;
    }
    int getAccountID() const {
        return accountID;
    }
    double getBalance() const {
        return balance;
    }
    void setBalance(double bal) {
        balance = bal;
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(int id, double bal) : BankAccount(id, bal) {}

    void withdraw_amount(double amount) {
        if (getBalance() - amount >= 5000) {
            setBalance(getBalance() - amount);
            cout << "Withdrawal of Rs. " << amount << " successful. Remaining balance: Rs. " << getBalance() << endl;
        } else {
            cout << "Cannot withdraw. Minimum balance limit will be violated" << endl;
        }
    }
};
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int id, double bal) : BankAccount(id, bal) {}

    void withdraw_amount(double amount) {
        if (getBalance() - amount >= 10000) {
            setBalance(getBalance() - amount);
            cout << "Withdrawal of Rs. " << amount << " successful. Remaining balance: Rs. " << getBalance() << endl;
        } else {
            cout << "Cannot withdraw. Minimum balance limit will be violated" << endl;
        }
    }
};
int main() {
    CurrentAccount current(12345, 10000);
    SavingsAccount savings(54321, 20000);
    current.balance_inquiry();
    current.deposit_amount(5000);
    current.withdraw_amount(6000);
    current.balance_inquiry();
    savings.balance_inquiry();
    savings.deposit_amount(5000);
    savings.withdraw_amount(6000);
    savings.balance_inquiry();
    return 0;
}