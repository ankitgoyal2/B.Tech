#include<iostream>
using namespace std;
struct node
{
    int info;
    node *ptr;
};
node *head,*start,*temp,*starteven,*startodd,*tempeven,*tempodd,*heade,*heado;
void create(int n)
{
    head=new node;
    head->info=n;
    if(start==NULL)
    {
        start=temp=head;
    }
    else
    {
        temp->ptr=head;
        temp=head;
    }
}
void display()
{
    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->info<<endl;
        temp=temp->ptr;
    }
}
void split()
{
    temp=start;
    if(temp==NULL)
        cout<<"underflow";
    else{
    while(temp!=NULL)
    {
        if((temp->info)%2==0)
        {cout<<"Even found";
          heade=temp;
           if(starteven==NULL)
            {
              starteven=tempeven=heade;
            }
           else
            {
             tempeven->ptr=heade;
             tempeven=heade;
            }
        }

        else
            {
                heado=temp;
                if(startodd==NULL)
                {
                    startodd=tempodd=heado;
                }
                else
                {
                    tempodd->ptr=heado;
                    tempodd=heado;
                }
            }
            temp=temp->ptr;
            }
            cout<<"\nLinked list with even no. is\n";
            tempeven=starteven;
    while(tempeven!=NULL)
    {
        cout<<tempeven->info<<endl;
        tempeven=tempeven->ptr;
    }
    cout<<"\nLinked list with odd no. is\n";
    tempodd=startodd;
    while(tempodd!=NULL)
    {
        cout<<tempodd->info<<endl;
        tempodd=tempodd->ptr;
    }
}
}
int main()
{
    int n,ch,m;
    ch=1;
    while(ch)
    {
        cout<<"Enter value to store"<<endl;
        cin>>n;
        create(n);
        cout<<"Want to create more :0 or 1\n";
        cin>>ch;
    }
    cout<<"\nValues in linked list are\n";

    split();


}
