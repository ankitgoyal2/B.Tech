#include<iostream>
using namespace std;
class abc
{
    int a;
public:
    void getdata(int x)
    {
        a=x;
    }
    void display()
    {
        cout<<"a="<<a<<"\n";
    }
};
int main()
{
    abc object;
    int x;
    cout<<"enter value \n";
    cin>>x;
    object.getdata(x);
    object.display();
}
