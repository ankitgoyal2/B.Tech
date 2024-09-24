/*
PROGRAM NAME = WRITE A PROGRAM TO SORT INTEGERS IN NON DECREASING ORDER USING HEAP SORT
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 23/01/2019  */

#include<bits/stdc++.h>
using namespace std;
void max_heapify(int array[],int i,int size)
{
    int j,left,right,largest;
    left=2*i+1;
    right=2*i+2;
    largest=i;
    if(array[largest]<array[left]&&left<size)
    {
        largest=left;
    }
    if(array[largest]<array[right]&&right<size)
    {
        largest=right;
    }
    if(largest!=i)
    {
        j=array[largest];
        array[largest]=array[i];
        array[i]=j;
        max_heapify(array,largest,size);
    }
}
int loop_count;
void heap_sort(int array[],int size)
{
    int i,j;
    for(i=size/2-1;i>=0;i--)
    {
        loop_count++;
        max_heapify(array,i,size);
    }
    for(i=size-1;i>=0;i--)
    {
        loop_count++;
        j=array[0];
        array[0]=array[i];
        array[i]=j;
        max_heapify(array,0,i);
    }
}
int main()
{
    int testcases;
    cout<<"enter no. of testcases\n";
    cin>>testcases;
    while(testcases--)
    {
        int i,j,k,size;
        loop_count=0;
        cout<<"enter no. of elements\n";
        cin>>size;
        int array[size];
        i=0;
        cout<<"enter array\n";
        while(i<size)
        {
            cin>>array[i];
            i++;
        }
        heap_sort(array,size);
        cout<<"sorted array is \n";
        i=0;
        while(i<size)
        {
            cout<<array[i]<<" ";
            i++;
        }
        cout<<"\ntotal no. of loops = "<<loop_count<<"\n";
    }
}
