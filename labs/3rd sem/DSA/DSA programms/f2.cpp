#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream abc;
    abc.open("ankit");
    char a;
    a=abc.get();
    while(!abc.eof())
    {
        cout<<a;
        a=abc.get();
    }
    abc.close();
}
