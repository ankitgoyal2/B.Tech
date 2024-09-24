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
};
class D
{
protected:
    int d;
};
class C:public B,public D
{
protected:
    int c;
public:
    void get_abcd(int x,int y,int z,int k)
    {
        a=x;
        b=y;
        c=z;
        d=k;
    }
    void display()
    {
        cout<<"a = "<<a<<"\nb = "<<b<<"\nc = "<<c<<"\nd = "<<d<<"\n";
    }
};
int main()
{
    int x,y,z,k;
    cout<<"enter four numbers\n";
    cin>>x>>y>>z>>k;
    C obj3;
    obj3.get_abcd(x,y,z,k);
    obj3.display();
}



