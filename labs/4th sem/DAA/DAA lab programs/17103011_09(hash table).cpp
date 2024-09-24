/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT HASH FUNCTION (DIVISION METHOD)
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 27/02/2019  */

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    node *next;
};
int main()
{
    int size,i,choice,temp1,temp2;
    node *p1,*p2;
    cout<<"press 1 for insert element\npress 2 for searching element\n";
    cout<<"press 3 for exit\nenter choice\n";
    cin>>choice;
    node *array[100]={NULL};
    int flag=0,count=0;
    while(choice!=3)
    {
        switch(choice)
        {
        case 1:
            cout<<"enter number\n";
            cin>>temp1;
            if(temp1<0)
                cout<<"negative number is not allowed\n";
            else
            {
            p1=new node;
            p1->info=temp1;
            p1->next=NULL;
            temp1=temp1%100;
            if(array[temp1]==NULL)
                array[temp1]=p1;
            else
            {
                p2=array[temp1];
                while(p2->next!=NULL)
                    p2=p2->next;
                p2->next=p1;
            }
            }
            break;
        case 2:
            cout<<"enter number\n";
            cin>>temp1;
            temp2=temp1%100;
            p1=array[temp2];
            flag=0,count=0;
            while(p1!=NULL)
            {
                count++;
                if(p1->info==temp1)
                {
                    flag=1;
                    break;
                }
                p1=p1->next;
            }
            if(count>1)
                cout<<"collision occured\n";
            if(flag==1)
                cout<<temp1<<" is present in the table\n";
            else
                cout<<temp1<<" is not present in the table\n";
            break;
        default:
            cout<<"invalid choice\n";
        }
        cout<<"enter choice\n";
        cin>>choice;
    }
}
