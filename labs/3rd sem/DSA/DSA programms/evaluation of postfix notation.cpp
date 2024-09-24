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
void push(int k,stack1 *n)
{
        n->top++;
        n->ptr[n->top]=k;
}
int pop(stack1 *n)
{
        n->top--;
        return n->ptr[n->top+1];
}
int main()
{
    stack1 *s;
    int i=0,j,k,l;
    char a[100];
    cout<<"enter string\n";
    cin>>a;
    s=create_stack(100);
    while(a[i]!='\0')
        i++;
    a[i]=')';
    i=0;
    while(a[i]!=')')
    {
        if(a[i]>=48&&a[i]<=57)
            push(a[i]-48,s);
        else
        {
            k=pop(s);
            j=pop(s);
            if(a[i]=='^')
               l=j^k;
            else if(a[i]=='/')
               l=j/k;
            if(a[i]=='*')
               l=j*k;
            if(a[i]=='+')
               l=j+k;
            if(a[i]=='-')
               l=j-k;
            push(l,s);
        }
        i++;
    }
    cout<<pop(s)<<"\n";
}

