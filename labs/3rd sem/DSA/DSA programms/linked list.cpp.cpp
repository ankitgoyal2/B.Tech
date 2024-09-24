#include<iostream>
using namespace std;
struct node
{
    int info;
    node *link;
};
class list1
{
    node *start=NULL;
public:
    void newnode(int s)
   {
    node *n,*t;
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
   void setdata()
   {
    node *t;
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
    node *t;
    t=start;
    while(t!=NULL)
    {
        cout<<t->info<<" ";
        t=t->link;
    }
    cout<<"\n";
  }
  void swapping(int k,int s)
  {
      node *p,*n,*temp,*t;
      if(s-k==1)
      {
          if(k==1)
          {
              n=start;
              p=n->link;
              temp=start;
              start=n->link;
              n->link=p->link;
              p->link=temp;
          }
          else
          {
              n=start;
              int i=2;
              while(i!=k)
              {
                  n=n->link;
                  i++;
              }
              p=n->link;
              temp=p->link;
              t=n->link;
              n->link=p->link;
              p->link=temp->link;
              temp->link=t;
          }
      }
      else
      {
          n=start;
          int i=2;
          while(i!=s)
          {
              n=n->link;
              i++;
          }
          t=n->link;
          if(k==1)
          {
              p=start;
              temp=start;
              start=n->link;
              n->link=temp;
              temp=p->link;
              p->link=t->link;
              t->link=temp;
          }
          else
          {
              p=start;
              int i=2;
              while(i!=k)
              {
                  p=p->link;
                  i++;
              }
              temp=p->link;
              node *m;
              m=temp->link;
              temp->link=t->link;
              t->link=m;
              m=p->link;
              p->link=n->link;
              n->link=m;
          }
      }
  }
};
int main()
{
    list1 a;
    int i,j,k,l;
    cout<<"Press 1 for create list\nPress 2 for set details\n";
    cout<<"Press 3 for display\nPress 4 for swapping nodes\n";
    cout<<"Press 5 for exit\n";
    cout<<"enter choice\n";
    cin>>k;
    while(k!=5)
    {
        switch(k)
        {
        case 1:
           cout<<"enter number of elements\n";
           cin>>i;
           a.newnode(i);
           break;
        case 2:
            a.setdata();
            break;
        case 3:
            a.display();
            break;
        case 4:
            cout<<"enter nodes to swap\n";
            cin>>i>>j;
            if(i>j)
            {
               l=i;
               i=j;
               j=l;
            }
            a.swapping(i,j);
            break;
        }
        cout<<"enter choice\n";
        cin>>k;
    }
}

