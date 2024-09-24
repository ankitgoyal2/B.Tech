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
inline void swap1(int &a,int &b)
{
    int c;
    c=a;
    a=b;
    b=c;
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
    int n,j=0;
    stack1 *low,*up;
    low=create_stack(100);
    up=create_stack(100);
    cout<<"enter number of elements\n";
    cin>>n;
    int a[n];
    cout<<"enter values\n";
    while(j!=n)
    {
        cin>>a[j];
        j++;
    }
    push(0,low);
    push(n-1,up);
    int beg,en,left,right,loc,k;
    while(low->top!=-1)
    {
        left=beg=pop(low);
        right=en=pop(up);
        loc=beg;
        j=1;
        k=1;
        while(j)
        {
            switch(k)
            {
            case 1:
                while(a[loc]<=a[right]&&loc!=right)
                {
                    right--;
                }
                if(loc==right)
                {
                    j=0;
                    break;
                }
                if(a[right]<a[loc])
                {
                    swap1(a[loc],a[right]);
                    loc=right;
                    k=2;
                }
                break;
            case 2:
                while(a[loc]>=a[left]&&loc!=left)
                {
                    left++;
                }
                if(loc==left)
                {
                    j=0;
                    break;
                }
                if(a[left]>a[loc])
                {
                    swap1(a[loc],a[left]);
                    loc=left;
                    k=1;
                }
                break;
            }
        }
        if(beg<loc-1)
        {
            push(beg,low);
            push(loc-1,up);
        }
        if(loc+1<en)
        {
            push(loc+1,low);
            push(en,up);
        }
    }
    j=0;
    while(j!=n)
    {
        cout<<a[j]<<" ";
        j++;
    }
    cout<<"\n";
}
