/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT PRIM'S ALGORITHM IN GRAPH
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 24/04/2019  */

#include<bits/stdc++.h>
using namespace std;
int find_min(int value[],int flag[],int n)
{
    int i=0,min=INT_MAX,index=-1;
    while(i<n)
    {
        if(flag[i]==0&&value[i]<min)
        {
            min=value[i];
            index=i;
        }
        i++;
    }
    return index;
}
void prim(int** matrix,int n)
{
    int value[n],par[n],flag[n],count=0,i=0,index;
    while(i<n)
    {
        value[i]=INT_MAX;
        par[i]=-1;
        flag[i]=0;
        i++;
    }
    value[0]=0;
    while(count<n-1)
    {
        index=find_min(value,flag,n);
        flag[index]=1;
        i=0;
        while(i<n)
        {
            if(matrix[index][i]>0&&flag[i]==0&&matrix[index][i]<value[i])
            {
                par[i]=index;
                value[i]=matrix[index][i];
            }
            i++;
        }
        count++;
    }
    cout<<"included edges are\n";
    i=1;
    while(i<n)
    {
        cout<<i<<"---"<<par[i]<<"\n";
        i++;
    }
}
int main()
{
    int n,edges,i=0,j;
    cout<<"enter no. of nodes and edges\n";
    cin>>n>>edges;
    cout<<"enter edge and weight of edge\n";
    int **matrix=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        matrix[i]=(int*)malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            matrix[i][j]=0;
    int temp1,temp2,temp3;
    i=0;
    while(i<edges)
    {
        cin>>temp1>>temp2>>temp3;
        matrix[temp1][temp2]=temp3;
        matrix[temp2][temp1]=temp3;
        i++;
    }
    prim(matrix,n);
}
