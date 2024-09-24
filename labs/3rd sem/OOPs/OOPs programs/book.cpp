#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int a;
class book
{
    char bname[10],aname[10];
    int count;
   public:
    void add();
    friend int search(book*,char*,char*);
    void lend();
    void return1();
    friend void display(book*);
};
void book::add()
{
    cout<<"enter book name,author and no of copies ";
    cin>>bname>>aname>>count;
    a++;
}
int search(book*c,char*s,char*t)
{
    for(int i=0;i<a;i++)
    {
        if(strcmp(c[i].bname,s)==0&&strcmp(c[i].aname,t)==0)
           return i;
    }
    return -1;
}
void book::lend()
{
    if(count>1)
    {
        cout<<"book lend";
        count-=1;
    }
    else
       cout<<"not sufficient copies to lend";
}
void book::return1()
{
    cout<<"book returned";
    count+=1;
}
void display(book *c)
{
    for(int i=0;i<a;i++)
       cout<<c[i].bname<<" "<<c[i].aname<<" "<<c[i].count<<"\n";
}
int main()
{
    book b[20];
    int i=0,f;
    char d[10],e[10];
    cout<<"1.add book\n"
        <<"2.search\n"
        <<"3.lend\n"
        <<"4.return\n"
        <<"5.display\n";
    char z='y';
    int choice;
    while(z=='y')
    {   cout<<"enter your choice";
        cin>>choice;
        switch(choice)
        {
             case 1:
                b[i].add();
                i++;
                break;
             case 2:
                cout<<"enter the book and author you want to search ";
                cin>>d>>e;
                f=search(b,d,e);
                if(f==-1)
                   cout<<"book is unavailable";
                else
                   cout<<"book is available";
                break;
             case 3:
                cout<<"enter the book and author to lend";
                cin>>d>>e;
                f=search(b,d,e);
                b[f].lend();
                break;
             case 4:
                cout<<"enter the book and author to return";
                cin>>d>>e;
                f=search(b,d,e);
                b[f].return1();
                break;
             case 5:
                display(b);
        }
        cout<<"want to continue";
        z=getche();
    }
}
