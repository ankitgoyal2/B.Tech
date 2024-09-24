#include<iostream>
using namespace std;
void swap(int x,int y)
{
    int z;
    z=x;
    x=y;
    y=z;
    cout<<"\nSwap by call by reference is :"<<endl;
    cout<<"X="<<x<<", Y="<<y;

}
int main()
{
    int a,b;
    cout<<"Enter two numbers";
    cin>>a>>b;
    cout<<"Numbers before swap";
    cout<<"X="<<a<<" ,Y="<<b;
    swap(a,b);
}
