#include<iostream>
using namespace std;
class complex1
{
    int i,j;
public:
    complex1(int x,int y)
    {
        i=x;j=y;
    }
    void sum(complex1 &a)
    {
        int x,y;
        x=i+a.i;
        y=j+a.j;
        cout<<"sum is "<<x<<"+"<<y<<"i\n";
    }
    void display()
    {
        cout<<i<<"+"<<j<<"i\n";
    }
    ~complex1()
    {
        display();
    }
};
int main()
{
    complex1 a(3,4),c(2,2);
    a.sum(c);
}

