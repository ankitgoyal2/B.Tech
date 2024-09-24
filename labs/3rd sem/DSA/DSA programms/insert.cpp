#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k,pos;
    cout<<"enter number of elements\n";
    cin>>n;
    int a[n+1];
    i=0;
    cout<<"enter values\n";
    while(i!=n)
    {
        cin>>a[i];
        i++;
    }
    cout<<"enter new position and value\n";
    cin>>pos>>k;
    j=n;
    while(j!=pos-2)
    {
        a[j+1]=a[j];
        j=j-1;
    }
    a[j+1]=k;
    i=0;
    while(i!=n+1)
    {
        cout<<a[i]<<" ";
        i++;
    }
}
