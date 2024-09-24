/*  PROGRAM NO. 1
PROGRAM NAME=INSERTION SORT
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
    int i,j,flag=0,n,key,loop_counter=0;
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
        loop_counter++;
        key=a[i+1];
        for(j=i;j>=0;j--)
        {
            loop_counter++;
            if(key<a[j])
            a[j+1]=a[j];
            else
                break;
        }
       a[j+1]=key;
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
