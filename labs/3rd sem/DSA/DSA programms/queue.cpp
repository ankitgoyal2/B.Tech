#include<iostream>
using namespace std;
class que
{
    int front1,rear,capacity;
    int *arr;
public:
    que()
    {
        front1=-1;
        rear=-1;
    }
    void create_que(int i)
    {
        capacity=i;
        arr=new int[i];
    }
    int isempty()
    {
        if(front1==-1)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if((rear+1)%capacity==front1)
            return 1;
        else
            return 0;
    }
    void setdata(int k)
    {
        if(!isfull())
        {
            rear=(rear+1)%capacity;
            arr[rear]=k;
            if(front1==-1)
                front1=rear;
        }
    }
    int getdata()
    {
        if(!isempty())
        {
            int k;
            k=arr[front1];
            if(front1==rear)
                front1=rear=-1;
            else
                front1=(front1+1)%capacity;
            return k;
        }
    }
    void display()
    {
        int i=front1,j=rear;
        while(i!=j)
        {
            cout<<arr[i]<<" ";
            i=(i+1)%capacity;
        }
        cout<<arr[j];
        cout<<"\n";
    }
};
int main()
{
    que a;
    int i,k;
    cout<<"Press 1 for create a queue\nPress 2 for push element\n";
    cout<<"Press 3 for pop element\nPress 4 for display\n";
    cout<<"Press 5 for exit\n";
    cout<<"enter choice\n";
    cin>>k;
    while(k!=5)
    {
        switch(k)
        {
        case 1:
            cout<<"enter size of queue\n";
            cin>>i;
            a.create_que(i);
            break;
        case 2:
            cout<<"enter element to push\n";
            cin>>i;
            a.setdata(i);
            break;
        case 3:
            i=a.getdata();
            cout<<"Poped element is "<<i<<"\n";
            break;
        case 4:
            a.display();
            break;
        }
        cout<<"enter choice\n";
        cin>>k;
    }
}
