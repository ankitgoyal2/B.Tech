/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT MATRIX CHAIN MULTIPLICATION
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 03/04/2019  */

#include<bits/stdc++.h>
using namespace std;
int mcm(int array[],int size)
{
    int m[size][size];
    int i,j,k,cost;
    for(i=1;i<size;i++)
        m[i][i]=0;
    for(int l=2;l<size;l++)
    {
        for(i=1;i<size-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                cost=m[i][k]+m[k+1][j]+array[i-1]*array[k]*array[j];
                if(cost<m[i][j])
                    m[i][j]=cost;
            }
        }
    }
    return m[1][size-1];
}
int main()
{
    int n;
    cout<<"enter no. of matrixes\n";
    cin>>n;
    int a[n+1];
    cout<<"enter array\n";
    for(int i=0;i<n+1;i++)
        cin>>a[i];
    cout<<"no. of  operations "<<mcm(a,n+1)<<"\n";
}
