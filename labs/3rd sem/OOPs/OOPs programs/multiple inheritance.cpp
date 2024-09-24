#include<iostream>
using namespace std;
class A
{
protected:
    int a;
public:
    void display_a()
    {
        cout<<"a = "<<a<<"\n";
    }
};
class B
{
protected:
    int b;
public:
     void display_b()
    {
        cout<<"b = "<<b<<"\n";
    }
};
class C:public A,public B
{
protected:
    int c;
public:
    void get_abc(int x,int y,int z)
    {
        a=x;
        b=y;
        c=z;
    }
    void display_c()
    {
        cout<<"c = "<<c<<"\n";
    }
};
int main()
{
    int x,y,z;
    cout<<"enter three numbers\n";
    cin>>x>>y>>z;
    C obj3;
    obj3.get_abc(x,y,z);
    obj3.display_a();
    obj3.display_b();
    obj3.display_c();
}

