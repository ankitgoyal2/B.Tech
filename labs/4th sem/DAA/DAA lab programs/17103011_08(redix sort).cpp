/*
PROGRAM NAME = WRITE A PROGRAM TO SORT IN NON DECREASING ORDER USING RADIX SORT
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 20/02/2019  */

#include<bits/stdc++.h>
using namespace std;
void counting_sort(int array[],int factor,int size)
{
    int i=0,count_array[10]={0};
    while(i<size)
    {
        count_array[(array[i]/factor)%10]++;
        i++;
    }
    i=1;
    while(i<10)
    {
        count_array[i]+=count_array[i-1];
        i++;
    }
    i=size-1;
    int temp_array[size];
    while(i>=0)
    {
        temp_array[count_array[(array[i]/factor)%10]-1]=array[i];
        count_array[(array[i]/factor)%10]--;
        i--;
    }
    i=0;
    while(i<size)
    {
        array[i]=temp_array[i];
        i++;
    }
}
int main()
{
    int testcases;
    cout<<"enter no. of testcases\n";
    cin>>testcases;
    while(testcases--)
    {
        int size,i,max;
        cout<<"enter size of array\n";
        cin>>size;
        int array[size];
        cout<<"enter array\n";
        cin>>array[0];
        max=array[0];
        i=1;
        while(i<size)
        {
            cin>>array[i];
            if(array[i]>max)
                max=array[i];
            i++;
        }
        int max_length=0;
        while(max>0)
        {
            max=max/10;
            max_length++;
        }
        int factor=1;
        while(max_length--)
        {
            counting_sort(array,factor,size);
            factor=factor*10;
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
