#include<iostream>
using namespace std;
int main()
{
    int a[100]={0},i,n,j;
    cout<<"enter number of elements in array\n";
    cin>>n;
    j=n;
    cout<<"enter numbers\n";
    while(j--)
    {
        cin>>i;
        a[i]++;

    }
    cout<<"\n";
    i=0;
    while(i!=100)
    {
        if(a[i]>0)
        {
            cout<<i<<"="<<a[i]<<" times\n";
        }
        i++;
    }
}
