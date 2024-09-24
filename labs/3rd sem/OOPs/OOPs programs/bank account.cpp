#include<iostream>
using namespace std;
class account
{
  static int lst;
  int a=0;
  char name[20];
public:
    int id;
    void setname()
    {
        cout<<"enter name and id\n";
        cin>>name>>id;
         lst=id;
    }
    void deposit(int b)
    {
        a=a+b;
        cout<<"Total bank balance is "<<a<<"\n";
    }
    void withdraw(int b)
    {
        if(a<b)
            cout<<"Not enough balance\n";
        else
         {
             a=a-b;
             cout<<"Total remaining bank balance is "<<a<<"\n";
         }
    }
    void display()
    {
        cout<<"Name="<<name<<"\n";
        cout<<"id="<<id<<"\n";
        cout<<"Your current balance is "<<a<<"\n\n";
    }
};

int account::lst;

int main()
{

    int b,a,i,k;
    cout<<"how many account you want to make\n";
    cin>>i;
    k=i;
    account my_account[i];
    cout<<"Press 1 for deposit    Press 2 for withdraw   Press 3 for display details\n";
    cout<<"Press 4 for exit\n";
    i=0;
    while(i!=k)
    {
        cout<<"enter details for "<<i+1<<" account\n";
        my_account[i].setname();
    cout<<"enter choice\n";
    cin>>a;
    while(a!=4)
    {
    switch(a)
    {
        case 1:
            cout<<"enter amount\n";
            cin>>b;
            my_account[i].deposit(b);
           break;
        case 2:
             cout<<"enter amount\n";
            cin>>b;
            my_account[i].withdraw(b);
          break;
        case 3:
            my_account[i].display();
            break;
    }
    cout<<"enter choice\n";
    cin>>a;
    }
    i=i+1;
    }

    int y,z=0,w=1;
    while(w)
    {
        cout<<"enter id you want to search\n";
        cin>>y;
         i=0;
    while(i!=k)
    {
        if(y==my_account[i].id)
        {
            z=1;
            break;
        }
        i++;
    }
    if(z==1)
        cout<<"id exist\n";
    else
        cout<<"id does not exist\n";
    cout<<"do you want to search another id enter 1 or 0\n";
    cin>>w;
    }
    i=0;
    cout<<"\n\nDetails of accounts\n\n";
    while(i!=k)
    {
        my_account[i].display();
        i++;
    }

}
