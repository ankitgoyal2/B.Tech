#include<iostream>
#include<conio.h>
using namespace std;
class set
{
    int a[10],len;
   public:
    void create_set();
    void is_member();
    void set_union(set,set);
    void set_intersection(set,set);
    void set_minus(set,set);
    void display();
};
void set::create_set()
{   int i;
    cout<<"enter no of elements of set ";
    cin>>len;
    cout<<"enter the elements ";
    for(i=0;i<len;i++)
        cin>>a[i];
}
void set::is_member()
{   int d,i;
    cout<<"enter the no you want to search ";
    cin>>d;
    for(i=0;i<len;i++)
    {
         if(a[i]==d)
            break;
    }
    if(i==len)
        cout<<"not present";
    else
       cout<<"present";
}
void set::set_union(set x,set y)
{
    int i,j,k=0;
    for(i=0;i<x.len;i++)
       a[k++]=x.a[i];

    for(i=0;i<y.len;i++)
    {
        for(j=0;j<x.len;j++)
        {
           if(y.a[i]==x.a[j])
             break;
        }
        if(j==x.len)
           a[k++]=y.a[i];
    }
    len=k;
}
void set::set_intersection(set x,set y)
{
    int i,j,k=0;
    for(i=0;i<x.len;i++)
    {
        for(j=0;j<y.len;j++)
        {
           if(x.a[i]==y.a[j])
             break;
        }
        if(j<y.len)
           a[k++]=x.a[i];
    }
    len=k;
}
void set::set_minus(set x,set y)
{
    int i,j,k=0;
    for(i=0;i<x.len;i++)
    {
        for(j=0;j<y.len;j++)
        {
           if(x.a[i]==y.a[j])
             break;
        }
        if(j==y.len)
           a[k++]=x.a[i];
    }
    len=k;
}
void set::display()
{   for(int i=0;i<len;i++)
       cout<<a[i]<<" ";
}
int main()
{   set A,B,C,D,E;
    A.create_set();
    B.create_set();
    cout<<"1.is member\n"
        <<"2.union\n"
        <<"3.intersection\n"
        <<"4.minus\n";
    int choice;
    char z='y';
    while(z=='y'){
    cout<<"enter your choice ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            A.is_member();
            break;
        case 2:
            C.set_union(A,B);
            C.display();
            break;
        case 3:
            D.set_intersection(A,B);
            D.display();
            break;
        case 4:
            E.set_minus(A,B);
            E.display();
    }
    cout<<"want to continue ";
    z=getche();}
    return 0;
}
