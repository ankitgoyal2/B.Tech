/*  PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT PRIORITY QUEUE USING MIN HEAP
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 13/02/2019  */

#include<bits/stdc++.h>
using namespace std;
void min_heapify(int array[],int i,int size)
{
    int j,left,right,least;
    left=2*i+1;
    right=2*i+2;
    least=i;
    if(array[least]>array[left]&&left<size)
        least=left;
    if(array[least]>array[right]&&right<size)
         least=right;
    if(least!=i)
    {
        j=array[least];
        array[least]=array[i];
        array[i]=j;
        min_heapify(array,least,size);
    }
}
int minimum(int array[])
{
    return array[0];
}
int extract_min(int array[],int &size)
{
    int minimum=array[0];
    array[0]=array[size-1];
    size=size-1;
    min_heapify(array,0,size);
    return minimum;
}
void decrease_key(int array[],int index,int key)
{
    if(key>array[index])
        cout<<"new key is larger than previous key\n";
    else
    {
        array[index]=key;
        while(index>0&&key<array[(index-1)/2])
        {
            int j=array[index];
            array[index]=array[(index-1)/2];
            array[(index-1)/2]=j;
            index=(index-1)/2;
        }
    }
}
void insert(int array[],int key,int &size)
{
    size=size+1;
    array[size-1]=INT_MAX;
    decrease_key(array,size-1,key);
}
void build_minheap(int array[],int size)
{
    int i;
    for(i=size/2-1;i>=0;i--)
        min_heapify(array,i,size);
}
int main()
{
    int i=0,temp,size;
    cout<<"enter no. of elements\n";
    cin>>size;
    int array[size];
    cout<<"enter array\n";
    while(i<size)
    {
        cin>>array[i];
        i++;
    }
    build_minheap(array,size);
    i=0;
    while(i<size)
    {
        cout<<array[i]<<" ";
        i++;
    }
    cout<<"\npress 1 for return minimum value\npress 2 for extract minimum element\n";
    cout<<"press 3 for decrease key\npress 4 for insert a new key\npress 6 to print queue\n";
    cout<<"press 5 for exit\nenter choice\n";
    int choice,index,key;
    cin>>choice;
    while(choice!=5)
    {
        switch(choice)
        {
        case 1:
            temp=minimum(array);
            cout<<"minimum value is "<<temp<<"\n";
            break;
        case 2:
            temp=extract_min(array,size);
            cout<<"minimum extracted value is "<<temp<<"\n";
            break;
        case 3:
            cout<<"enter index and key \n";
            cin>>index>>key;
            decrease_key(array,index-1,key);
            break;
        case 4:
            cout<<"enter new key to insert\n";
            cin>>key;
            insert(array,key,size);
            break;
        case 6:
            i=0;
             while(i<size)
             {
                     cout<<array[i]<<" ";
                      i++;
              }
              cout<<"\n";
              break;
        default:
            cout<<"invalid input\n";
        }
        cout<<"enter choice\n";
        cin>>choice;
    }
}
