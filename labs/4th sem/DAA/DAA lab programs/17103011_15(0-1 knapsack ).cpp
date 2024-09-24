/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT 0-1 KNAPSACK PROBLEM
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 10/04/2019  */

#include<bits/stdc++.h>
using namespace std;
int knapsack(int value[],int weight[],int w,int size)
{
    int i,j,k,m[size+1][w+1],temp[size+1][w+1];
    for(i=0;i<size+1;i++)
    {
        for(j=0;j<w+1;j++)
        {
            temp[i][j]=0;
            if(i==0||j==0)
                m[i][j]=0;
            else if(weight[i-1]>j)
            {
                 m[i][j]=m[i-1][j];
                 temp[i][j]=1;
            }
            else
            {
                 m[i][j]=max(m[i-1][j],m[i-1][j-weight[i-1]]+value[i-1]);

                 if(m[i-1][j]>=m[i-1][j-weight[i-1]]+value[i-1])
                    temp[i][j]=1;
                 else
                    temp[i][j]=2;
            }
        }
    }
    for(i=0;i<size+1;i++)
    {
        for(j=0;j<w+1;j++)
        {
            cout<<temp[i][j]<<" ";
        }
        cout<<"\n";
    }
    i=size;
    j=w;
    cout<<"included values are\n";
    while(j>0)
    {
        if(temp[i][j]==2)
        {
            cout<<value[i-1]<<" ";
            i--;
            j=j-weight[i];
        }
        else
            i--;
    }
    cout<<"\n";
    return m[size][w];
}
int main()
{
    int n,w;
    cout<<"enter no. of values and weight of knapsack\n";
    cin>>n>>w;
    int value[n],weight[n];
    cout<<"enter values and weights\n";
    for(int i=0;i<n;i++)
        cin>>value[i]>>weight[i];
    cout<<"total value "<<knapsack(value,weight,w,n)<<"\n";
}
