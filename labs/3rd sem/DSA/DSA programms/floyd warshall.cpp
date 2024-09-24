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
            temp->matrix[i][j]=99999;
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
        cout<<"enter the weight of node:";
        cin>>k;
        temp->matrix[i-1][j-1]=k;
        //temp->matrix[j-1][i-1]=1;
    }
    return temp;
}
void floyd_short(graph *head)
{
    int i,j,k;
    for(i=0;i<head->v;i++)
    {
        for(j=0;j<head->v;j++)
        {
            for(k=0;k<head->v;k++)
            {
                if(head->matrix[i][k]+head->matrix[k][j]<head->matrix[i][j])
                {
                    head->matrix[i][j]=head->matrix[i][k]+head->matrix[k][j];
                }
            }
        }
    }
}
int main()
{
    graph *head=create();
    floyd_short(head);
    for(int i=0;i<head->v;i++)
    {
        for(int j=0;j<head->v;j++)
        {
            cout<<setw(10)<<head->matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

