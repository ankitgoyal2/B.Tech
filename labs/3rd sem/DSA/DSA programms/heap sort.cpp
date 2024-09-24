#include<bits/stdc++.h>
using namespace std;
void heapisation(int *no,int n,int i)
{
    if(i>=1 && i<n)
    {
        if(no[i]>no[(i-1)/2])
        {
            int temp=no[i];
            no[i]=no[(i-1)/2];
            no[(i-1)/2]=temp;
            i=(i-1)/2;
            heapisation(no,n,i);
        }
    }
}
int deletion(int *no,int *n,int i)
{
    int x=no[i],temp;
    no[i]=no[*n];
    if(2*i+2<*n)
    {
        if(no[i]<no[2*i+1] || no[i]<no[2*i+2])
        {
            temp=no[i];
            no[i]=max(no[2*i+1],no[2*i+2]);
            if(no[i]==no[2*i+1])
            {
                no[2*i+1]=temp;
                i=2*i+1;
            }
            else
            {
                no[2*i+2]=temp;
                i=2*i+2;
            }
            deletion(no,n,i);
        }
    }
    else if(2*i+1<*n)
    {
        if(no[i]<no[2*i+1])
        {
            temp=no[i];
            no[i]=(no[2*i+1]);
            no[2*i+1]=temp;
            i=2*i+1;
            deletion(no,n,i);
        }
    }
    return x;
}
void print(int *no,int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<no[i]<<" ";
    cout<<"\n";
}
int main()
{
    int no[100],n,i,x;
    cout<<"enter no. of elements :";
    cin>>n;
    x=n;
    for(i=0;i<n;i++)
    {
        cin>>no[i];
        heapisation(no,n,i);
    }
    cout<<"sorted array is :\n";
    for(i=0;i<x;i++)
    {
        n=n-1;
        cout<<deletion(no,&n,0)<<" ";
    }
}

