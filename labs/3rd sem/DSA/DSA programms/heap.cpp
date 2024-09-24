#include<iostream>
using namespace std;
void delete_root(int *a,int &n)
{
    int ptr=1,item,left=2,right=3,last;
     item=a[1];
     cout<<item<<"\n";
     last=a[n];
     n=n-1;
     while(right<=n)
     {
         if(last>=a[left]&&last>=a[right])
        {
            a[ptr]=last;
            break;
        }
        if(a[left]>=a[right])
        {
            a[ptr]=a[left];
            ptr=left;
        }
        else
        {
            a[ptr]=a[right];
            ptr=right;
        }
        left=2*ptr;
        right=left+1;
     }
     if(left==n&&last<a[left])
     {
          a[ptr]=a[left];
          ptr=left;
     }
     a[ptr]=last;
}
int main()
{
     int n,i=1,j,k=0,x;
     cout<<"enter total number of nodes\n";
     cin>>n;
     int a[n+1];
     cout<<"enter nodes\n";
     while(i<n+1)
     {
         cin>>a[i];
         k=i;
         abc:if(i!=1&&a[k]>a[k/2])
         {
             j=a[k];
             a[k]=a[k/2];
             a[k/2]=j;
             if(k/4>=1)
               k=k/2;
             if(a[k]>a[k/2])
                goto abc;
         }
         i++;
     }
     i=1;
     while(i<n+1)
     {
         cout<<a[i]<<" ";
         i++;
     }
     cout<<"\n";
     i=1;
     x=n;
     while(i<x+1)
     {
         delete_root(a,n);
         i++;
     }
}
