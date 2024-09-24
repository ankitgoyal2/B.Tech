#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
struct arrstack
{
    int top;
    unsigned cap;
    int *ptr;
};
arrstack *temp;
void create_stack()
{
    temp=(arrstack *)malloc(sizeof(arrstack*));
    temp->top=0;
    temp->cap=20;
    temp->ptr=(int *)malloc(sizeof(int)*temp->cap);
}
void push(int x)
{
    temp->ptr[temp->top]=x;
    temp->top++;
}
int pop()
{
    int t;
        t=temp->ptr[temp->top-1];
        temp->top--;
        return t;
}
main()
{
    int i=0,x,y,value,t;
    create_stack();
    char s[50];
    cout<<"enter a string\n";
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            t=0;
            while(s[i]!=',')
            {
                t=(t*10)+s[i]-48;
                i++;
            }
            push(t);
        }
        else if(s[i]=='*')
        {
            x=pop();
            y=pop();
            t=y*x;
            push(t);
        }
        else if(s[i]=='+')
        {
            x=pop();
            y=pop();
            t=y+x;
            push(t);
        }
        else if(s[i]=='-')
        {
            x=pop();
            y=pop();
            t=y-x;
            push(t);
        }
        else if(s[i]=='/')
        {
            x=pop();
            y=pop();
            t=y/x;
            push(t);
        }
    }
    value=pop();
    cout<<value;
}
