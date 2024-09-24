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
class C:public B
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
    void display()
    {
        cout<<"a = "<<a<<"\nb = "<<b<<"\nc = "<<c<<"\n";
    }
};
int main()
{
    int x,y,z;
    cout<<"enter three numbers\n";
    cin>>x>>y>>z;
    C obj3;
    obj3.get_abc(x,y,z);
    obj3.display();
}


