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
struct arraystack
{
    int top,cap;
    int *no;
};
struct arrayqueue
{
    int base,rear,cap,*no;
};
arrayqueue* create_q(int n)
{
    arrayqueue *temp=new arrayqueue;
    temp->base=-1;
    temp->rear=-1;
    temp->cap=n;
    temp->no=new int[n];
}
bool full(arrayqueue *head)
{
    if((head->rear+1)%head->cap==head->base)
        return 1;
    return 0;
}
bool blank(arrayqueue *head)
{
    if(head->base==-1)
        return 1;
    else
        return 0;
}
void enqueue(arrayqueue *head,int n)
{
    if(!full(head))
    {
        head->rear=(head->rear+1)%head->cap;
        head->no[head->rear]=n;
        if(head->base==-1)
            head->base=head->rear;
    }
}
int dequeue(arrayqueue *head)
{
    if(!blank(head))
    {
        int n=head->no[head->base];
        if(head->base==head->rear)
            head->base=head->rear=-1;
        else
            head->base=(head->base+1)%head->cap;
            return n;
    }
}
arraystack* create(int n)
{
    arraystack *temp=new arraystack;
    temp->top=-1;
    temp->cap=n;
    temp->no=(int*)malloc(sizeof(int)*n);
    return temp;
}
bool full(arraystack *head)
{
    if(head->top+1==head->cap)
        return 1;
    return 0;
}
bool blank(arraystack *head)
{
    if(head->top==-1)
        return 1;
    return 0;
}
void push(arraystack *head,int n)
{
    if(!full(head))
    {
        head->top++;
        head->no[head->top]=n;
    }
}
int pop(arraystack *head)
{
    int n;
    if(!blank(head))
    {
        n=head->no[head->top];
        head->top--;
        return n;
    }
}
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
    for(i=0;i<temp->v;i++)
        for(j=0;j<temp->v;j++)
            temp->matrix[i][j]=0;
    //temp->matrix=(int**)mat;
    cout<<"enter the no of edges :";
    cin>>temp->e;
    cout<<"enter source and destination of edges:";
    for(x=0;x<temp->e;x++)
    {
        cin>>i>>j;
        temp->matrix[i-1][j-1]=1;
        temp->matrix[j-1][i-1]=1;
    }
    return temp;
}
void dfs(graph *head)
{
    int i;
    arraystack *s=create(head->v);
    for(i=0;i<head->v;i++)
    {
        if(head->nodes[i]->state==0)
        {
            head->nodes[i]->state=1;
            push(s,i);
        }
        while(!blank(s))
        {
            int x=pop(s),j;
            cout<<head->nodes[x]->data<<" ";
            head->nodes[x]->state=2;
            for(j=0;j<head->v;j++)
            {
                //cout<<head->matrix[x][j];
                if(head->matrix[x][j]==1)
                {
                    //cout<<2;
                    if(head->nodes[j]->state==0)
                    {
                    head->nodes[j]->state=1;
                    push(s,j);
                    }
                }
            }
        }
    }
}
void bfs(graph *head)
{
    int i,j;
    arrayqueue *q=create_q(head->v);
    for(i=0;i<head->v;i++)
    {
        if(head->nodes[i]->state==0)
        {
            head->nodes[i]->state=1;
            enqueue(q,i);
        }
        while(!blank(q))
        {
            int x=dequeue(q);
            if(head->nodes[x]->state!=2)
            {
                cout<<head->nodes[x]->data<<" ";
                head->nodes[x]->state=2;
            }
            for(j=0;j<head->v;j++)
            {
                if(head->matrix[x][j]==1)
                {
                    if(head->nodes[j]->state==0)
                    {
                        head->nodes[i]->state=1;
                        enqueue(q,j);
                    }
                }
            }
        }
    }
}
int main()
{
    graph *head=create();
    cout<<"bfs:\n";
   bfs(head);
   int i=0;
   while(i<head->v)
   {
       head->nodes[i]->state=0;
       i++;
   }
   cout<<"\n";
   cout<<"dfs:\n";
   dfs(head);
}
