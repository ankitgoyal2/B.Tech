#include<iostream>
using namespace std;
int fun(int num)
{
    if(num%2==0)
        return num/2;
    else
        return num*3+1;
}
int main()
{
    while(1)
    {


    int num,i;
    cin>>num;
    cout<<"\n";
    while(1)
    {
        num=fun(num);
        cout<<num<<"\n";
        if(num==1)
            break;
    }
    }
}
