//class club to store details
#include<iostream>
#include<stdio.h>
using namespace std;
class club
{
    string name;
    int member_id;
    string address;
    int dom;
public:
    void initialize(void);
    void display(void);
};
void club::initialize(void)
{
    fflush(stdin);
    cout<<"enter name: ";
    getline(cin,name);
    cout<<"enter member-id: ";
    cin>>member_id;
    cout<<"enter address: ";
    fflush(stdin);
    getline(cin,address);
    cout<<"enter duration of membership: ";
    cin>>dom;
}
void club::display(void)
{
    cout<<"NAME: "<<name<<"\nMEMBER_ID: "<<member_id<<"\nADDRESS: "<<address<<"\nDURATION OF MEMBERSHIP: "<<dom<<endl;
}
main()
{
    int c=1;
    int n=0,i;
    club a[20];
    for(i=0;c!=0;i++)
    {
        a[i].initialize();
        cout<<"do want to continue?(enter 0 or 1)";
        cin>>c;
        n++;
    }
    cout<<endl<<endl;
    for(i=0;i<n;i++)
    {
        a[i].display();
        cout<<endl;
    }
    cout<<"TOTAL NO. OF MEMBERS: "<<n;
}
