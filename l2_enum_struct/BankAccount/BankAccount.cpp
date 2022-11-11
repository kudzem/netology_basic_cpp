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
        std::cout << "�� ����� " << account_number << " �� ��� " << owner << ": " << balance << std::endl;
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
    std::cout << "������� ����� ����� : ";
    std::cin >> account_number;
    std::string owner;
    std::cout << "������� ��� ��������� : ";
    std::cin >> owner;

    BankAccount myAccount = BankAccount(account_number, owner);

    double balance;
    std::cout << "������� ������ : ";
    std::cin >> balance;
    ChangeAccountBalance(myAccount, balance);
    std::cout << "������� ����� ������ : ";
    std::cin >> balance;
    ChangeAccountBalance(myAccount, balance);

    myAccount.PrintBalance();
}