/*
PROGRAM NAME = WRITE A PROGRAM TO SORT INTEGERS IN NON DECREASING ORDER USING QUICK SORT
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 23/01/2019
*/
#include<bits/stdc++.h>
#include<map>
using namespace std;
int partition(int[],int,int);
void quick_sort(int array[],int first,int last)
{
    if(first<last)
    {
        int pivot=partition(array,first,last);
        quick_sort(array,first,pivot-1);
        quick_sort(array,pivot+1,last);
    }
}
int comparision;
int partition(int array[],int low,int high)
{
    int i,j,k;
    i=low-1;
    int pivot=array[high];
    for(j=low;j<high;j++)
    {
        comparision++;
        if(array[j]<pivot)
        {
            i++;
            k=array[j];
            array[j]=array[i];
            array[i]=k;
        }
    }
    k=array[i+1];
    array[i+1]=array[high];
    array[high]=k;
    return (i+1);
}

int main()
{
    int testcases;
    cout<<"enter number of testcases\n";
    cin>>testcases;
    while(testcases--)
    {
        comparision=0;
    int i,j,size,flag=0;
    map<int,int> m;
    cout<<"enter size of array\n";
    cin>>size;
    int array[size];
    i=0;
    cout<<"enter array\n";
    while(i<size)
    {
        cin>>array[i];
        m[array[i]]++;
        if(m[array[i]]>1)
        {
            flag=1;
        }
        i++;
    }
    if(flag==1)
        cout<<"invalid input\n";
    else
    {
        quick_sort(array,0,size-1);
        cout<<"sorted array is\n";
        for(i=0;i<size;i++)
           cout<<array[i]<<" ";
        cout<<"\nno. of comparisions = "<<comparision<<"\n";
    }
    }
}
