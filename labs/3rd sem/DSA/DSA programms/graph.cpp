#include<iostream>
using namespace std;
struct stack1
{
    int top,size1;
    int *ptr;
};
stack1* create_stack(int k)
{
    stack1 *n;
    n=new stack1;
    n->top=-1;
    n->size1=k;
    n->ptr=new int[k];
    return n;
}
int isfull(stack1 *n)
{
    if(n->top==n->size1-1)
        return 1;
    else
        return 0;
}
int isempty(stack1 *n)
{
    if(n->top==-1)
        return 1;
    else
        return 0;
}
void push(int k,stack1 *n)
{
    if(!isfull(n))
    {
        n->top++;
        n->ptr[n->top]=k;
    }
}
int pop(stack1 *n)
{
    if(!isempty(n))
    {
        n->top--;
        return n->ptr[n->top+1];
    }
}
void display(stack1 *n)
{
    int a,b=0;
    a=n->top;
    while(b!=a+1)
    {
        cout<<n->ptr[b]<<" ";
        b++;
    }
    cout<<"\n";
}
    void traverse(int v[],int e[10][10],int a)
    {
        int x[a]={0},y,z=0,i,j,k;
        stack1 *s;
        s=create_stack(a);
        i=0;
        x[i]=1;
        push(i,s);
        while(s->top!=-1)
        {
            y=pop(s);
            push(y,s);
            z=0;
            for(j=0;j<a;j++)
            {
                if(e[y][j]>0&&x[j]==0)
                {
                    z+=1;
                    push(j,s);
                    x[j]=1;
                }
                if(z==0&&j==a-1)
                {
                    k=pop(s);
                    cout<<v[k]<<" ";

                }
            }
        }
        cout<<"\n";

    }
int main()
{
    int a,b,i=0,j,k;
    cout<<"enter vertex and edges\n";
    cin>>a>>b;
    int v[a]={0},e[10][10];
    cout<<"enter values of vertexes\n";
    while(i!=a)
    {
        cin>>v[i];
        i++;
    }
    k=b;
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
    {
        e[i][j]=0;
    }
    }
    while(k)
    {
        cout<<"enter vertexes whom edge connect\n";
        cin>>i>>j;
        e[i-1][j-1]+=1;
        k--;
    }
    traverse(v,e,a);
}
