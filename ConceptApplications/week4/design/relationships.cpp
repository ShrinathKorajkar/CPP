#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <algorithm>

/*
src/
│── ui/
│   ├── main.cpp
│   ├── Menu.cpp / Menu.h
│
│── business/
│   ├── Bank.cpp / Bank.h
│   ├── Account.cpp / Account.h
│   ├── Admin.cpp / Admin.h
│   ├── AccountHolder.cpp / AccountHolder.h
│   ├── Transaction.cpp / Transaction.h
│
│── data/
│   ├── BankRepository.cpp / BankRepository.h
│   ├── FileStorage.cpp / FileStorage.h
*/

enum class TransactionType
{
    DEPOSIT,
    WITHDRAW
};

class Transaction
{
    std::string date;
    TransactionType type;
    double amount;

public:
    Transaction(TransactionType type, double amount)
        : type(type), amount(amount)
    {
        // Set current date
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buf[20];
        strftime(buf, sizeof(buf), "%Y-%m-%d", ltm);
        date = buf;
    }

    void print() const
    {
        std::cout << date << " | "
                  << (type == TransactionType::DEPOSIT ? "Deposit" : "Withdraw")
                  << " | " << amount << "\n";
    }
};

class Account
{
    int accountNumber;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account(int accNo, double initialBalance = 0.0)
        : accountNumber(accNo), balance(initialBalance) {}

    int getAccountNumber() const { return accountNumber; }

    void deposit(double amount)
    {
        balance += amount;
        transactions.emplace_back(TransactionType::DEPOSIT, amount);
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        transactions.emplace_back(TransactionType::WITHDRAW, amount);
        return true;
    }

    void printMiniStatement() const
    {
        std::cout << "Mini Statement for Account " << accountNumber << ":\n";
        for (const auto &txn : transactions)
        {
            txn.print();
        }
        std::cout << "Current Balance: " << balance << "\n";
    }
};

class Bank; // Forward declaration

class User
{
protected:
    std::string name;
    int userId;

public:
    User(std::string name, int userId)
        : name(std::move(name)), userId(userId) {}

    virtual ~User() = default;
    int getUserId() const { return userId; }
};

class AccountHolder : public User
{
public:
    using User::User;

    void deposit(Bank &bank, int accountNumber, double amount);
    void withdraw(Bank &bank, int accountNumber, double amount);
    void getMiniStatement(Bank &bank, int accountNumber) const;
};

class Admin : public User
{
public:
    using User::User;

    void createAccount(Bank &bank, int accountHolderId);
    void deleteAccount(Bank &bank, int accountNumber);
    void viewAllAccounts(const Bank &bank) const;
};

class Bank
{
    std::vector<Account> accounts;

    void addAccount(int accountNumber, double initialBalance = 0.0)
    {
        accounts.emplace_back(accountNumber, initialBalance);
    }

    void removeAccount(int accountNumber)
    {
        accounts.erase(std::remove_if(accounts.begin(), accounts.end(),
                                      [accountNumber](const Account &acc)
                                      {
                                          return acc.getAccountNumber() == accountNumber;
                                      }),
                       accounts.end());
    }

    const std::vector<Account> &getAllAccounts() const
    {
        return accounts;
    }

public:
    Account *findAccount(int accountNumber)
    {
        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accountNumber)
                return &acc;
        }
        return nullptr;
    }

    friend class Admin;
};

// ===== Implement AccountHolder functions =====
void AccountHolder::deposit(Bank &bank, int accountNumber, double amount)
{
    if (auto acc = bank.findAccount(accountNumber))
    {
        acc->deposit(amount);
    }
    else
    {
        std::cout << "Account not found!\n";
    }
}

void AccountHolder::withdraw(Bank &bank, int accountNumber, double amount)
{
    if (auto acc = bank.findAccount(accountNumber))
    {
        acc->withdraw(amount);
    }
    else
    {
        std::cout << "Account not found!\n";
    }
}

void AccountHolder::getMiniStatement(Bank &bank, int accountNumber) const
{
    if (auto acc = bank.findAccount(accountNumber))
    {
        acc->printMiniStatement();
    }
    else
    {
        std::cout << "Account not found!\n";
    }
}

// ===== Implement Admin functions =====
void Admin::createAccount(Bank &bank, int accountHolderId)
{
    static int accountCounter = 1001;
    bank.addAccount(accountCounter++);
    std::cout << "Account created for User ID " << accountHolderId << "\n";
}

void Admin::deleteAccount(Bank &bank, int accountNumber)
{
    bank.removeAccount(accountNumber);
    std::cout << "Account " << accountNumber << " deleted.\n";
}

void Admin::viewAllAccounts(const Bank &bank) const
{
    const auto &accs = bank.getAllAccounts();
    std::cout << "All Accounts in Bank:\n";
    for (const auto &acc : accs)
    {
        std::cout << "Account Number: " << acc.getAccountNumber() << "\n";
    }
}
