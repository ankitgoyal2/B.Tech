#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int info;
    int priority;
    node *link;
};
node *start=NULL,*t,*n,*en=NULL;
node* newnode()
{
    node *n;
    n=new node;
    n->link=NULL;
    return n;
}
void insert_node(int k)
{
    n=new node;
    n->link=NULL;
    n->info=k;
    en->link=n;
    en=n;
}
void setdata(int s)
{
    while(s--)
    {
    n=newnode();
    cout<<"enter info and priority\n";
    cin>>n->info>>n->priority;
    if(start==NULL)
    {
        start=n;
        en=n;
    }
    else
    {
        node *p=NULL;
        t=start;
        if(n->priority<t->priority)
        {
           start=n;
           start->link=t;
        }
        else
        {
            while(t->priority<=n->priority&&t->link!=NULL)
            {
               p=t;
               t=t->link;
            }
           if(t->priority==n->priority)
              p=n;
           else
              t=n;
        }
        t=start;
        while(t->link!=NULL)
            t=t->link;
        en=t;
    }

    }
}
void delete_node()
{
    t=start->link;
    delete start;
    start=t;
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
int main()
{
    cout<<"press 1 for create queue\npress 2 for insert a node\n";
    cout<<"press 3 for delete a node\npress 4 for display queue\npress 5 for exit\n";
    int i,j,k;
    cout<<"enter choice\n";
    cin>>k;
    while(k!=5)
    {
        switch(k)
        {
        case 1:
            cout<<"enter number of elements\n";
            cin>>i;
            setdata(i);
            break;
        case 2:
            cout<<"enter info\n";
            cin>>i;
            insert_node(i);
            break;
        case 3:
            delete_node();
            break;
        case 4:
            display();
            break;
        }
        cout<<"enter choice\n";
        cin>>k;
    }
}

