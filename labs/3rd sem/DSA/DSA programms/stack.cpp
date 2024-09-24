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
int main()
{
    stack1 *s;
    int i,j,a,k;
    cout<<"Press 1 for create a stack\nPress 2 for push element\n";
    cout<<"Press 3 for pop element\nPress 4 for display\n";
    cout<<"Press 5 for exit\n";
    cout<<"enter choice\n";
    cin>>a;
    while(a!=5)
    {
        switch(a)
        {
        case 1:
            cout<<"enter size of stack\n";
            cin>>i;
            s=create_stack(i);
            break;
        case 2:
            cout<<"enter element to push\n";
            cin>>i;
            push(i,s);
            break;
        case 3:
            i=pop(s);
            cout<<"Poped element is "<<i<<"\n";
            break;
        case 4:
            display(s);
            break;
        }
        cout<<"enter choice\n";
        cin>>a;
    }
}
