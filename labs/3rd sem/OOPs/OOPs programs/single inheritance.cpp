#include<iostream>
using namespace std;
class A
{
protected:
    int a;
};
class B:public A
{
protected:
    int b;
public:
    void get_ab(int x,int y)
    {
        a=x;
        b=y;
    }
    void display()
    {
        cout<<"a = "<<a<<"\nb = "<<b<<"\n";
    }
};
int main()
{
    int x,y;
    cout<<"enter two numbers\n";
    cin>>x>>y;
    B obj2;
    obj2.get_ab(x,y);
    obj2.display();
}

