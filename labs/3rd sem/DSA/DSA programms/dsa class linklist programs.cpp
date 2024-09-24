#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insertion(node **,int );
node* create(int n)
{
    node *temp=new node;
    temp->next=NULL;
    temp->data=n;
    return temp;
}
node *createlist()
{
    int i,n,x;
    cout<<"enter the length of 1 list :";
    cin>>n;
    cout<<"enter the data :";
    cin>>x;
    node *temp1=create(x);
    for(i=1;i<n;i++)
    {
        cin>>x;
        insertion(&temp1,x);
    }
    return temp1;
}
void insertion(node **head,int n)
{
    node *temp=*head;
    if(temp==NULL)
    {
        *head=new node;
        (*head)->data=n;
        (*head)->next=NULL;
    }
    else
    {
        while((temp)->next!=NULL)
        {
            (temp)=(temp)->next;
        }
        (temp)->next=new node;
            (temp)->next->next=NULL;
            (temp)->next->data=n;
    }
}
void print(node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}
void freq_sorted(node *temp)
{
    int c=1;
    while(temp->next!=NULL)
    {
        int x=temp->data;
        if(temp->data==temp->next->data)
        {
            c++;
        }
        else
        {
            cout<<temp->data<<"-"<<c<<"\n";
            c=1;
        }
        temp=temp->next;
        if(temp->next==NULL)
        {
            cout<<temp->data<<"-"<<c<<"\n";
        }
    }
}
void freq_unsorted(node *head)
{
    node *temp1=head,*temp2;
    while(temp1!=NULL)
    {
        temp2=temp1->next;
        int c=1;
        while(temp2!=NULL)
        {
            if(temp1->data==temp2->data)
            {
                c++;
                temp2->data=temp2->next->data;
                temp2->next=temp2->next->next;
            }
            else
             temp2=temp2->next;
        }
        cout<<temp1->data<<" - "<<c<<"\n";
        temp1=temp1->next;
    }
}
void reverselist(node **head)
{
    node *temp=*head,*t;
     while(temp->next!=NULL)
    {
        t=temp->next;
        temp->next=t->next;
        t->next=*head;
        *head=t;
    }
}
node* concatenate()
{
   node *temp1=createlist(),*temp2=createlist();
    node *t=temp1;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp2;
    return t;
}


int main()
{

    cout<<"enter ur choice: 1 for searching in sorted \n 2 for searching in unsorted \n 3 for reversing 4 for concatenation \n 5 for print";
    node *head=NULL;
    while(1)
    {
        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1:
            head=createlist();
            freq_sorted(head);
            break;
        case 2:
            head=createlist();
            freq_unsorted(head);
            break;
        case 3:
            head=createlist();
            reverselist(&head);
            break;
        case 4:
            head=concatenate();
            break;
        case 5:
            print(head);
            break;
        case 6:
            exit(0);

        }
    }
}
