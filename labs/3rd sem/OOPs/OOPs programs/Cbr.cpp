#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
}
int main()
{
    int a,b;
    cout<<"Enter two numbers:";
    cin>>a>>b;
    cout<<"\nNumbers before swap:\n";
    cout<<"X="<<a<<", Y="<<b;
    swap(&a,&b);
    cout<<"\nNumbers after swap:\n";
    cout<<"X="<<a<<",Y="<<b;
}
