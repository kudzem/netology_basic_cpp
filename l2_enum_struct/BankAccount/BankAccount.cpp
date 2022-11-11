// BankAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct BankAccount {
    BankAccount(long account_number, 
                std::string owner, 
                double balance = 0) : account_number(account_number),
                                      owner(owner),
                                      balance(balance) {}

private:
    long account_number;
    std::string owner;
    double balance;
public:
    void PrintBalance() {
        std::cout << "На счёту " << account_number << " на имя " << owner << ": " << balance << std::endl;
    }

    friend void ChangeAccountBalance(struct BankAccount& account, double new_balance);
};

void ChangeAccountBalance(struct BankAccount& account, double new_balance) {
    account.balance = new_balance;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    long account_number;
    std::cout << "Введите номер счёта : ";
    std::cin >> account_number;
    std::string owner;
    std::cout << "Введите имя владельца : ";
    std::cin >> owner;

    BankAccount myAccount = BankAccount(account_number, owner);

    double balance;
    std::cout << "Введите баланс : ";
    std::cin >> balance;
    ChangeAccountBalance(myAccount, balance);
    std::cout << "Введите новый баланс : ";
    std::cin >> balance;
    ChangeAccountBalance(myAccount, balance);

    myAccount.PrintBalance();
}