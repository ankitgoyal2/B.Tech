#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data,state;
};
struct graph
{
    int v,e,**matrix;
    node **nodes;
};
graph* create()
{
    graph *temp=new graph;
    int i,j,x;
    cout<<"enter the no. of vertices :";
    cin>>temp->v;
    temp->matrix=(int**)malloc(sizeof(int)*(temp->v));
    for(i=0;i<temp->v;i++)
        temp->matrix[i]=new int[temp->v];
    int mat[temp->v][temp->v];
    temp->nodes=(node**)malloc(sizeof(node)*temp->v);
    for(i=0;i<temp->v;i++)
    {
        node *y=new node;
        cout<<"enter the data of node :";
        cin>>y->data;
        y->state=0;
        temp->nodes[i]=y;
    }
    cout<<1;
    for(i=0;i<temp->v;i++)
        for(j=0;j<temp->v;j++)
            temp->matrix[i][j]=0;
     for(i=0;i<temp->v;i++)
        temp->matrix[i][i]=0;
    //temp->matrix=(int**)mat;
    cout<<"enter the no of edges :";
    cin>>temp->e;
    cout<<"enter source and destination of edges:";
    for(x=0;x<temp->e;x++)
    {
        cin>>i>>j;
        int k;
        //cout<<"enter the weight of node:";
        //cin>>k;
        temp->matrix[i-1][j-1]=1;
        //temp->matrix[j-1][i-1]=1;
    }
    return temp;
}
int** path(graph *temp)
{
    int i,j,k,l,t[temp->v][temp->v];
    int **path=(int**)malloc(sizeof(int)*(temp->v));
    for(i=0;i<temp->v;i++)
        path[i]=new int[temp->v];
    int **path1=(int**)malloc(sizeof(int)*(temp->v));
    for(i=0;i<temp->v;i++)
        path1[i]=new int[temp->v];
    for(i=0;i<temp->v;i++)
    {
        for(j=0;j<temp->v;j++)
        {
           path[i][j]=temp->matrix[i][j];
            path1[i][j]=temp->matrix[i][j];
        }
    }
    for(l=0;l<(temp->v)-1;l++)
    {
        for(i=0;i<temp->v;i++)
        {
            for(j=0;j<temp->v;j++)
            {
                int sum=0;
                for(k=0;k<temp->v;k++)
                {
                    sum=sum+(path[i][k]*(temp->matrix[k][j]));
                }
                t[i][j]=sum;
            }
        }
        for(int m=0;m<temp->v;m++)
        {
            for(int n=0;n<temp->v;n++)
            {
                path[m][n]=t[m][n];
                path1[m][n]=path[m][n]+path1[m][n];
            }
        }

    }
    return path1;
}
int main()
{
    int i,j;
    graph *head=create();
    for(i=0;i<head->v;i++)
    {
        for(j=0;j<head->v;j++)
        {
            cout<<head->matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    int **p=path(head);
    cout<<"\npath matrix :\n";
    for(i=0;i<head->v;i++)
    {
        for(j=0;j<head->v;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<"\n";
    }

}
