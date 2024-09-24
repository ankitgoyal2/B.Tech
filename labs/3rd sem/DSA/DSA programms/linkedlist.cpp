#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node
{
   int num;
   struct node*ptr;
};
node*start;
node* createlinkedlist();
void displaylinkedlist(node *);
void modifylinkedlist(node*);
void unsortedsearch(node*,int);
void sortedsearch(node*,int);
void insertbeginning(node*,int);
void insertunsorted(node*,int,int);
void insertsorted(node*,int);
void delete1(node*,int);
void reverse1(node*);
void swapcon(node*,int,int);
void swapnoncon(node*,int,int);
void split(node*);
void merge1(node*,node*);
void frequency();
int main()
{
    start=createlinkedlist();
    char z='y';int d;
    while(z=='y'){
    cout<<"1.display linked list\n"
        <<"2.modify linked list\n"
        <<"3.search for an item\n"
        <<"4.insert\n"
        <<"5.delete\n"
        <<"6.reverse\n"
        <<"7.swap con\n"
        <<"8.swap noncon\n"
        <<"9.split\n"
        <<"merge\n"
        <<"10.frequency\n";
    int choice;
    cout<<"enter your choice ";
    cin>>choice;
    switch(choice)
    {
        case 1:
               displaylinkedlist(start);
               break;
        case 2:
               modifylinkedlist(start);
               cout<<"modified linked list\n";
               displaylinkedlist(start);
               break;
        case 3:cout<<"1.list is unsorted\n"
                   <<"2.list is sorted";
               cin>>d;
               switch(d)
               {
                  case 1:
                      cout<<"enter the item to be searched ";
                      cin>>d;
                      unsortedsearch(start,d);
                      break;
                  case 2:
                      cout<<"enter the item to be searched";
                      cin>>d;
                      sortedsearch(start,d);
               }break;
        case 4:
              cout<<"1.insertion at the beginning\n";
              cout<<"2.insertion in an unsorted list\n";
              cout<<"3.insertion in a sorted list\n";
              cout<<"enter your choice ";
              int c;
              cin>>c;
              switch(c)
              {
                  case 1:cout<<"enter the item to insert";
                         int a;
                         cin>>a;
                         insertbeginning(start,a);
                         displaylinkedlist(start);
                         break;
                  case 2:
                         cout<<"enter the item to be inserted and at position";
                         int e,f;
                         cin>>e>>f;
                         insertunsorted(start,e,f);
                         displaylinkedlist(start);
                         break;
                  case 3:
                         cout<<"enter the item";
                         cin>>e;
                         insertsorted(start,e);
                         displaylinkedlist(start);
              }
              break;
          case 5:
                 cout<<"enter the item you want to delete " ;
                 cin>>d;
                 delete1(start,d);
                 displaylinkedlist(start);
                 break;
          case 6:
                reverse1(start);
                displaylinkedlist(start);
                break;
          case 7:
                cout<<"enter node nos";
                int a,b;
                cin>>a>>b;
                swapcon(start,a,b);
                displaylinkedlist(start);
                break;
          case 8:
                cout<<"enter node nos";
                cin>>a>>b;
                swapnoncon(start,a,b);
                displaylinkedlist(start);
                break;
          case 9:
                split(start);
                break;
          case 10:
                frequency();
    }
    cout<<"want to continue";
    z=getche();cout<<endl;}
}
node* createlinkedlist()
{
   node*head,*temp=0,*first=0;
   char another='y';
   while(another=='y')
   {
       head=(node*)malloc(sizeof(node));
       cout<<"enter item ";
       cin>>head->num;
       if(first!=0)
       {
          temp->ptr=head;
          temp=head;
       }
       else
          first=temp=head;
       cout<<"want to add another ";
       another=getche();
       cout<<endl;
    }
   temp->ptr=0;
   return first;
}
void displaylinkedlist(node*p)
{
    while(p!=0)
    {
        cout<<p->num<<" ";
        p=p->ptr;
    }
}
void modifylinkedlist(node*a)
{
    while(a!=0)
    {
        a->num*=2;
        a=a->ptr;
    }
}
void unsortedsearch(node*p,int a)
{   int pos=1;
    while(p!=0)
    {
        if(p->num==a)
            break;
        pos++;
        p=p->ptr;
    }
    if(p==0)
        cout<<"not present";
    else
        cout<<"present at position "<<pos;
}
void sortedsearch(node*b,int e)
{   int pos=1;
    while(b!=0)
    {   if(b->num==e){
             cout<<"found at position"<<pos;
             return;}
        else if(b->num>e)
             break;
        pos++;
        b=b->ptr;
    }
        cout<<"not found";
}
void insertunsorted(node*p,int a,int b)
{   int i;
    if(b==1)
        insertbeginning(p,a);
    else{
    for(i=2;i<b;i++)
        p=p->ptr;
    node*n=new node;
    n->num=a;
    n->ptr=p->ptr;
    p->ptr=n;}
}
void insertsorted(node*p,int a)
{   node*m=0;
    while(p!=0)
    {
        if(p->num>a)
           break;
        m=p;
        p=p->ptr;
    }
    if(m==0)
        insertbeginning(start,a);
    else{
    node*n=new node;
    n->num=a;
    n->ptr=m->ptr;
    m->ptr=n;}
}
void insertbeginning(node*p,int b)
{
    node*n=new node;
    n->num=b;
    n->ptr=p;
    p=n;
    start=p;
}
void delete1(node*p,int a)
{   node*m=0;
    while(p!=0)
    {
        if(p->num==a)
            break;
        m=p;
        p=p->ptr;
    }
    if(m==0)
      start=p->ptr;
    else if(p==0)
        cout<<"item not present";
    else
        m->ptr=p->ptr;
}
void reverse1(node*p)
{
    node*m=0,*n;
    while(p!=0)
    {   n=p->ptr;
        p->ptr=m;
        m=p;
        p=n;
    }
    start=m;
}
void swapcon(node*p,int d,int e)
{
   node*m,*n;
   int f=d<e?d:e;
   if(f==1)
   {   n=p->ptr->ptr;
       p->ptr->ptr=p;
       start=p->ptr;
       p->ptr=n;
   }
   else{
   for(int i=1;i<f;i++)
   {   m=p;
       p=p->ptr;}
   n=p->ptr->ptr;
   p->ptr->ptr=p;
   m->ptr=p->ptr;
   p->ptr=n;}
}
void swapnoncon(node*p,int d,int e)
{
    node*x,*m,*n;
    for(int i=1;i<e;i++)
    {   if(i<d)
          n=p;
        m=p;
        p=p->ptr;
    }
    if(d==1)
    {
        x=m->ptr->ptr;
        m->ptr->ptr=start->ptr;
        m->ptr=start;
        start->ptr=x;
        start=p;
    }
    else{
    x=m->ptr->ptr;
    m->ptr->ptr=n->ptr->ptr;
    m->ptr=n->ptr;
    n->ptr->ptr=x;
    n->ptr=p;}
}
void split(node*p)
{
    node*start1=0,*start2=0,*p1,*p2;
    while(p!=0)
    {
        if(p->num%2==0)
        {
            if(start1==0)
            {
                start1=p;
                p1=start1;
            }
            else
            {
                p1->ptr=p;
                p1=p;
            }
        }
        else
        {
            if(start2==0)
            {
                start2=p;
                p2=start2;
            }
            else
            {
                p2->ptr=p;
                p2=p;
            }
        }
        p=p->ptr;
    }
    p1->ptr=0;
    p2->ptr=0;
    displaylinkedlist(start1);
    cout<<endl;
    displaylinkedlist(start2);
    merge1(start1,start2);
}
void merge1(node*start1,node*start2)
{
    node*p1=start1,*p2=start2;
    node*p,*staart=0;
    while(p1!=0&&p2!=0)
    {
         if(staart==0)
         {
             if(p1->num<p2->num)
             {
                 staart=start1;
                 p=staart;
                 p1=p1->ptr;
             }
             else
             {
                 staart=start2;
                 p=staart;
                 p2=p2->ptr;
             }
         }
         else
         {
             if(p1->num<p2->num)
             {
                 p->ptr=p1;
                 p=p->ptr;
                 p1=p1->ptr;
             }
             else
             {
                 p->ptr=p2;
                 p=p->ptr;
                 p2=p2->ptr;
             }
         }
    }
    if(p1!=0)
         p->ptr=p1;
    else
         p->ptr=p2;
    cout<<endl;
    displaylinkedlist(staart);
    start=staart;
}
void frequency()
{   node*p,*q;
    int count;
    for(p=start;p!=0;p=p->ptr)
    {
        for(q=start;q!=p;q=q->ptr)
        {
             if(p->num==q->num)
                 break;
        }
        if(q==p)
        {    count=1;
             for(q=p->ptr;q!=0;q=q->ptr)
                 if(p->num==q->num)
                      count++;
             cout<<p->num<<" "<<count<<"\n";
        }
    }
}



