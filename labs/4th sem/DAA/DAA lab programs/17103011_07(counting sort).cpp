/*
PROGRAM NAME = WRITE A PROGRAM TO SORT IN NON DECREASING ORDER USING COUNTING SORT
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 20/02/2019  */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cout<<"enter no. of testcases\n";
    cin>>testcases;
    while(testcases--)
    {
        int size,i,max,min,range;
        cout<<"enter size of array\n";
        cin>>size;
        int array[size];
        cout<<"enter array\n";
        cin>>array[0];
        min=max=array[0];
        i=1;
        while(i<size)
        {
            cin>>array[i];
            if(array[i]>max)
                max=array[i];
            if(array[i]<min)
                min=array[i];
            i++;
        }
        range=max-min+1;
        int arr_range[range]={0};
        i=0;
        while(i<size)
        {
            arr_range[array[i]-min]+=1;
            i++;
        }
        i=0;
        int element=min-1,freq=0;
        while(i<size)
        {
            if(freq==0)
            {
                element++;
                freq=arr_range[element-min];
            }
            else
            {
                array[i]=element;
                freq--;
                i++;
            }
        }
        cout<<"sorted array is \n";
        i=0;
        while(i<size)
        {
            cout<<array[i]<<" ";
            i++;
        }
        cout<<"\n";
    }
}
