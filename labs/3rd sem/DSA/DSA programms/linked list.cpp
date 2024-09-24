#include<iostream>
using namespace std;
struct node
{
    int info;
    node *link;
};
node *start=NULL,*t,*n;
void newnode(int s)
{
    while(s--)
    {
        n=new node;
        n->link=NULL;
        if(start==NULL)
            start=n;
        else
        {
            t=start;
            while(t->link!=NULL)
                t=t->link;
            t->link=n;
        }
    }
}
void setdata(int s)
{
    newnode(s);
    t=start;
    while(t!=NULL)
    {
        cout<<"enter info\n";
        cin>>t->info;
        t=t->link;
    }
}
void display()
{
    t=start;
    while(t!=NULL)
    {
        cout<<t->info<<" ";
        t=t->link;
    }
    cout<<"\n";
}
void newstring(node a,node b)
{
    node *p;
    t=a.start;
    n=b.start;
    while(t!=NULL||n!=NULL)
    {
        if(n->link<=t->link)
        {
            p=new node;
        }
    }
}
int main()
{
    int k,l;
    cout<<"enter no. of elements\n";
    cin>>k;
    setdata(k);
    display();
}
