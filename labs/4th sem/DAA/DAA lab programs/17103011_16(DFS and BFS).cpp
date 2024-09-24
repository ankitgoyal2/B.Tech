/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT DEPTH FIRST SEARCH AND BREADTH FIRST SEARCH IN GRAPH
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 24/04/2019  */

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int value,status;
};
void dfs(node array[],int **matrix,int n,int edges)
{
    int i=0,j,k;
    node temp;
    stack <node> s;
    while(i<n)
    {
        if(array[i].status==0)
        {
            s.push(array[i]);
            while(!s.empty())
            {
                temp=s.top();
                s.pop();
                j=0;
                while(j<n)
                {
                    if(temp.value==array[j].value)
                        break;
                    j++;
                }
                array[j].status=2;
                cout<<array[j].value<<" ";
                k=0;
                while(k<n)
                {
                    if(matrix[j][k]==1&&array[k].status==0)
                    {
                        array[k].status=1;
                        s.push(array[k]);
                    }
                    k++;
                }
            }
        }
        i++;
    }
}
void bfs(node array[],int **matrix,int n,int edges)
{
    int i=0,j,k;
    node temp;
    queue <node> q;
    while(i<n)
    {
        if(array[i].status==0)
        {
            q.push(array[i]);
            while(!q.empty())
            {
                temp=q.front();
                q.pop();
                j=0;
                while(j<n)
                {
                    if(temp.value==array[j].value)
                        break;
                    j++;
                }
                array[j].status=2;
                cout<<array[j].value<<" ";
                k=0;
                while(k<n)
                {
                    if(matrix[j][k]==1&&array[k].status==0)
                    {
                        array[k].status=1;
                        q.push(array[k]);
                    }
                    k++;
                }
            }
        }
        i++;
    }
}
int main()
{
    int n,edges;
    cout<<"enter no. of nodes and edges\n";
    cin>>n>>edges;
    cout<<"enter nodes\n";
    node array[n];
    int i=0,j;
    while(i<n)
    {
        cin>>array[i].value;
        array[i].status=0;
        i++;
    }
    cout<<"enter edges\n";
    int **matrix=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        matrix[i]=(int*)malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            matrix[i][j]=0;
    int temp1,temp2;
    i=0;
    while(i<edges)
    {
        cin>>temp1>>temp2;
        matrix[temp1][temp2]=1;
        i++;
    }
    cout<<"DFS = ";
    dfs(array,matrix,n,edges);
    cout<<"\n";
    for(j=0;j<n;j++)
        array[j].status=0;
    cout<<"BFS = ";
    bfs(array,matrix,n,edges);
}
