/*
PROGRAM NAME = WRITE A PROGRAM TO FIND MINIMUM SPANNING TREE USING KRUSKAL'S ALGORITHM
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 24/04/2019  */

#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int s,d,value;
};
bool compare(edge e1,edge e2)
{
    if(e1.value>e2.value)
        return 0;
    return 1;
}
int find_parent(int par[],int temp)
{
    while(par[temp]!=-1)
        temp=par[temp];
    return temp;
}
void kruskal_algo(edge array[],int n,int edges)
{
    int par[n],count=0,i=0,index,set1,set2,temp3,edge_count=0;
    sort(array,array+edges,compare);
    for(i=0;i<n;i++)
        par[i]=-1;
    queue <int> q;
    while(count<n-1)
    {
        set1=find_parent(par,array[edge_count].s);
        set2=find_parent(par,array[edge_count].d);
        if(set1!=set2)
        {
            count++;
            q.push(edge_count);
            par[set1]=set2;
        }
        edge_count++;
    }
    cout<<"included edges are\nn1---n2  weight\n ";
    while(q.empty()!=1)
    {
        i=q.front();
        cout<<array[i].s<<"---"<<array[i].d<<"     "<<array[i].value<<"\n ";
        q.pop();
    }
}
int main()
{
    int n,edges,i=0,j;
    cout<<"enter no. of nodes and edges\n";
    cin>>n>>edges;
    cout<<"enter edge and weight of edge\n";
    edge array[edges];
    i=0;
    while(i<edges)
    {
        cin>> array[i].s>>array[i].d>>array[i].value;
        i++;
    }
    kruskal_algo(array,n,edges);
}

