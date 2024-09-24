#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node* create(int n)
{
    node *temp=new node;
    temp->next=NULL;
    temp->data=n;
    return temp;
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
int largest(node *temp)
{
    int largest=temp->data;
    while(temp!=NULL)
    {
        if(largest<temp->data)
        {
            largest=temp->data;
        }
        temp=temp->next;
    }
    return largest;
}
int searching(node *temp,int n)
{
    while(temp!=NULL)
    {
        if(n==temp->data)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
void double_value(node *temp)
{
     while(temp!=NULL)
    {
        temp->data=temp->data*2;
        temp=temp->next;
    }
}
void sum(node *temp)
{
    int sum=0;
     while(temp!=NULL)
    {
        sum=temp->data+sum;
        temp->data=sum;
        temp=temp->next;
    }
}
void sum_last(node *temp)
{
    int sum,x;
    while(temp!=NULL)
    {
        x=temp->data;
        temp->data=x+sum;
        sum=x;
        temp=temp->next;
    }
}
node* sorting(node *head)
{
    node *temp=head,*small=head;
    if(head->next==NULL)
        return head;
    while(temp!=NULL)
    {
        if(temp->data<small->data)
        {
            small=temp;
        }
        temp=temp->next;
    }
    head->next=small->next;
    small->next=head;
    small->next=sorting(small->next);
    return small;
}


int main()
{
    node *head=NULL;
    int ch,x,y;
    cout<<"1 insertion \n2 largest\n3 search\n4double each value\n5 previous elements\n6 sum only last one\n7 print\n8 sorting\n9 exit\n";
    while(1)
    {
        cout<<"enter your choice :";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"enter data :";
            cin>>x;
            insertion(&head,x);
            break;
        case 2:
            y=largest(head);
            cout<<y<<"\n";
            break;
        case 3:
            cout<<"enter element u want to search :";
            cin>>y;
            if(searching(head,y))
                cout<<"yes it is present \n";
            else
                cout<<"no it is not present \n";
            break;
        case 4:
            double_value(head);
            break;
        case 5:
            sum(head);
            break;
        case 6:
            sum_last(head);
            break;
        case 7:
            print(head);
            break;
        case 8:
          //  head=sorting(head);
            break;
        case 9:
            exit(0);
            break;

        default:
            cout<<"enter correct choice :";
        }
    }
}
