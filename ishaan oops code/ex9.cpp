#include <iostream>
#include <exception>
using namespace std;

class BankException : public exception {
public:
    const char* what() const noexcept override {
        return "Banking Error!";
    }
};

class InsufficientBalance : public BankException {
public:
    const char* what() const noexcept override {
        return "Insufficient Balance!";
    }
};

class InvalidAmount : public BankException {
public:
    const char* what() const noexcept override {
        return "Invalid withdrawal amount!";
    }
};

class MinimumBalance : public BankException {
public:
    const char* what() const noexcept override {
        return "Minimum Balance of 500 must be maintained!";
    }
};

class Bank {
private:
    double balance;

public:
    Bank(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientBalance();
        }

        if (balance - amount < 500) {
            throw MinimumBalance();
        }

        balance = balance - amount;
        cout << "Withdrawal Successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main() {
    Bank account(5000);

    try {
        double amount;

        cout << "Enter withdrawal amount: ";
        cin >> amount;

        account.withdraw(amount);
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const MinimumBalance& e) {
        cout << e.what() << endl;
    }
    catch (const BankException& e) {
        cout << e.what() << endl;
    }

    return 0;
}