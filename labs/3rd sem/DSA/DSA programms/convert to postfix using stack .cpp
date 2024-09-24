#include<iostream>
using namespace std;
struct stack1
{
    int top,size1;
    char *ptr;
};
stack1* create_stack(int k)
{
    stack1 *n;
    n=new stack1;
    n->top=-1;
    n->size1=k;
    n->ptr=new char[k];
    return n;
}
void push(char k,stack1 *n)
{
        n->top++;
        n->ptr[n->top]=k;
}
char pop(stack1 *n)
{
        n->top--;
        return n->ptr[n->top+1];
}
int main()
{
    stack1 *s;
    char a[100],b[100]={'\0'},c;
    s=create_stack(100);
    cout<<"Enter string\n";
    cin>>a;
    int i=0,j=0;
    while(a[i]!='\0')
        i++;
    a[i]=')';
    push('(',s);
    i=0;
    j=0;
    while(s->top!=-1)
    {
        if(a[i]>=48&&a[i]<=57)
        {
            b[j]=a[i];
            j++;
            cout<<b<<"\n";
        }
        else if(a[i]!='('&&a[i]!=')')
        {
            if(a[i]=='^')
               push('^',s);
            else if(a[i]=='/'||a[i]=='*')
            {
               abc: c=pop(s);
                if(c=='^')
                {
                    b[j]=c;
                    j++;
                    goto abc;
                }
                else
                    push(c,s);
                push(a[i],s);
            }
            else if(a[i]=='+'||a[i]=='-')
            {
               bcd: c=pop(s);
                if(c=='^'||c=='*'||c=='/')
                {
                    b[j]=c;
                    j++;
                    goto bcd;
                }
                else
                    push(c,s);
                push(a[i],s);
            }
            cout<<b<<"\n";
        }
        else if(a[i]=='(')
            push(a[i],s);
        else if(a[i]==')')
        {
            while(1)
            {
                c=pop(s);
                if(c=='(')
                    break;
                else
                {
                    b[j]=c;
                    j++;
                }
            }
            cout<<b<<"\n";
        }
        i++;
    }
    cout<<b<<"\n";
}

