#include <iostream>
#include <string>
using namespace std;

class Account
{
    int initialBalance;

public:

    Account(){}
    Account(int balance)
    {
        setInitialBalance(balance);
    }
    void setInitialBalance(int balance)
    {
        if(balance >= 0)
        {
            initialBalance = balance;
        }
        else if(balance < 0)
        {
            initialBalance = 0;
            cout << "Error, invalid amount";
        }
    }
    int getBalance()
    {
        return initialBalance;
    }
    int withdrawBalance(int w)
    {
        intialBalance == (initialBalance - w);
    }
};

int main()
{
    int w,b;
    cout << "Deposit money into account: ";
    cin >> b;

    Account balance;
    balance.setInitialBalance(b);

    cout << "The balance is: " << balance.getBalance();

    cout << "Enter amount to withdraw: ";
    cin >> w;


    balance.withdrawBalance(w);
    cout << "The new balance is: "balance.getBalance();
    return 0;
}
