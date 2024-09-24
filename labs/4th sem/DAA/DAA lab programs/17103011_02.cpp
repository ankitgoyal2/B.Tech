/*  PROGRAM NO. 2
PROGRAM NAME=SELECTION SORT
ROLL NO. = 17103011
DATE = 09/01/2019   */
#include<iostream>
using namespace std;
int main()
{
    int testcase;
    cout<<"enter no. of testcases\n";
    cin>>testcase;
    while(testcase--)
    {
    int i,j,flag=0,k,n,minimum,loop_counter=0;
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
        loop_counter++;
        k=i;
        for(j=i+1;j<n;j++)
        {
            loop_counter++;
            if(a[j]<a[k])
            {
                k=j;
            }
        }
        j=a[k];
        a[k]=a[i];
        a[i]=j;
    }
    cout<<"sorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nloop count = "<<loop_counter<<"\n";
    }
    }
}

