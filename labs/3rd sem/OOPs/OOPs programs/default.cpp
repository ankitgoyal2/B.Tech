#include<iostream>
using namespace std;
int sum(int b=3,int c=6)
{
    return (b+c);
}
int main()
{
    int a,b;
    cout<<"Enter two no.";
    cin>>a>>b;
    cout<<"Sum with no parameter as default :"<<sum(a,b)<<endl;
    cout<<"Sum with second parameter as default :"<<sum(a)<<endl;
    cout<<"Sum with both parameter as default :"<<sum()<<endl;

}
