#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void calculateInterest() = 0;

    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount Deposited Successfully" << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount Withdrawn Successfully" << endl;
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    void displayAccountInfo()
    {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Holder Name    : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * interestRate / 100;

        cout << "Savings Interest : " << interest << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= getBalance() + overdraftLimit)
        {
            cout << "Withdrawal Successful" << endl;
        }
        else
        {
            cout << "Overdraft Limit Exceeded" << endl;
        }
    }

    void calculateInterest() override
    {
        cout << "Current Account has no interest." << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
    int term;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t)
        : BankAccount(accNo, name, bal)
    {
        term = t;
    }

    void calculateInterest() override
    {
        double interest = getBalance() * 0.07 * term / 12;

        cout << "Fixed Deposit Interest : " << interest << endl;
    }
};

int main()
{
    vector<BankAccount *> accounts;

    int choice;

    do
    {
        cout << "\n-- BANKING SYSTEM --" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Current Account" << endl;
        cout << "3. Create Fixed Deposit Account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. Display Account Info" << endl;
        cout << "7. Calculate Interest" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter Your Choice : ";
        cin >> choice;

        int accNo, term;
        string name;
        double bal, rate, limit, amt;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Account No : " << endl;
            cin >> accNo;

            cout << "Enter Holder Name : " << endl;
            cin.ignore();
            getline(cin, name);

            cout << "Enter Balance : " << endl;
            cin >> bal;

            cout << "Enter Interest Rate : " << endl;
            cin >> rate;

            accounts.push_back(
                new SavingsAccount(accNo, name, bal, rate));

            cout << "Savings Account Created Successfully" << endl;

            break;
        }

        case 2:
        {
            cout << "Enter Account No : " << endl;
            cin >> accNo;

            cout << "Enter Holder Name : " << endl;
            cin.ignore();
            getline(cin, name);

            cout << "Enter Balance : " << endl;
            cin >> bal;

            cout << "Enter Overdraft Limit : " << endl;
            cin >> limit;

            accounts.push_back(
                new CheckingAccount(accNo, name, bal, limit));

            cout << "Current Account Created Successfully" << endl;

            break;
        }

        case 3:
        {
            cout << "Enter Account No : " << endl;
            cin >> accNo;

            cout << "Enter Holder Name : " << endl;
            cin.ignore();
            getline(cin, name);

            cout << "Enter Balance : " << endl;
            cin >> bal;

            cout << "Enter Term (Months) : " << endl;
            cin >> term;

            accounts.push_back(
                new FixedDepositAccount(accNo, name, bal, term));

            cout << "Fixed Deposit Account Created Successfully" << endl;

            break;
        }

        case 4:
        {
            if (accounts.empty())
            {
                cout << "No Accounts Available" << endl;
                break;
            }

            cout << "Enter Deposit Amount : " << endl;
            cin >> amt;

            accounts.back()->deposit(amt);

            break;
        }

        case 5:
        {
            if (accounts.empty())
            {
                cout << "No Accounts Available" << endl;
                break;
            }

            cout << "Enter Withdraw Amount : " << endl;
            cin >> amt;

            accounts.back()->withdraw(amt);

            break;
        }

        case 6:
        {
            if (accounts.empty())
            {
                cout << "No Accounts Available" << endl;
                break;
            }

            accounts.back()->displayAccountInfo();

            break;
        }

        case 7:
        {
            if (accounts.empty())
            {
                cout << "No Accounts Available" << endl;
                break;
            }

            accounts.back()->calculateInterest();

            break;
        }

        case 8:
        {
            cout << "Thank You" << endl;
            break;
        }

        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }

    } while (choice != 8);

    // Memory Release
    for (int i = 0; i < accounts.size(); i++)
    {
        delete accounts[i];
    }

    return 0;
}