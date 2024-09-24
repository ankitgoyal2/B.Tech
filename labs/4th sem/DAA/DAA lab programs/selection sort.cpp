#include<iostream>
using namespace std;
int main()
{
    int l;
    cout<<"enter testcases\n";
    cin>>l;
    while(l--)
    {
    int i,j,flag=0,k,n,minimum;
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
    for(i=0;i<n-1;i++)
    {

        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[k])
            {
                k=j;
            }
        }
        j=a[k];
        a[k]=a[i];
        a[i]=j;
    }
    cout<<"\nsorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    }
    }
}
