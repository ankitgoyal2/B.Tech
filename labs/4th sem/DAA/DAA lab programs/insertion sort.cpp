#include<iostream>
using namespace std;
int main()
{
    int i,j,flag=0,n,key;
    cout<<"enter size of array\n";
    cin>>n;
    int a[n];
    cout<<"enter array\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            flag=1;
    }
    if(flag)
        cout<<"invalid input\n";
    else
    {
    for(i=0;i<n;i++)
    {
        key=a[i+1];
        for(j=i;j>=0;j--)
        {
            if(key<a[j])
            a[j+1]=a[j];
            else
                break;
        }
       a[j+1]=key;
    }
    cout<<"\nsorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    }
}

