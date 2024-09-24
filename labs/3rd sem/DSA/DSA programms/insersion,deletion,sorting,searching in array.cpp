#include<iostream>
#include<stdlib.h>
using namespace std;
void sorting(int*,int);
void insertion_beg(int *no,int *n)
{
    int i;
    for(i=(*n)-1;i>=0;i--)
    {
        no[i+1]=no[i];
    }
    cout<<"enter the no. u want to insert :\n";
    cin>>no[0];
    *n=(*n)+1;
}
void insertion_mid(int *no,int *n)
{
    int i,temp;
    cout<<"enter the index at which u want to insert :\n";
    cin>>temp;
    for(i=*(n)-1;i>=temp;i--)
    {
        no[i+1]=no[i];
    }
    cout<<"enter the no u want to insert :\n";
    cin>>no[temp];
    *n=(*n)+1;
}
void insertion_end(int *no,int *n)
{
    cout<<"enter the element u want to insert :\n";
    cin>>no[*n];
    *n=(*n)+1;
}
void delete_mid(int *no,int *n)
{
    int i,temp;
    cout<<"enter the index at which u want to delete :\n";
    cin>>temp;
    for(i=temp+1;i<*n;i++)
    {
        no[i-1]=no[i];
    }
    *n=(*n)-1;
}
void delete_element(int *no,int *n)
{
    int temp,i,j;
    cout<<"enter the element u want to delete\n";
    cin>>temp;
    for(i=*n-1;i>=0;i--)
    {
        if(temp==no[i])
        {
            for(j=i+1;j<*n;j++)
            {
                no[j-1]=no[j];
            }
            i--;
            *n=(*n)-1;
        }
    }
}
void linear_search(int *no,int n)
{
    int temp,i,j,flag;
    cout<<"enter the no. u want to search :\n";
    cin>>temp;
    for(i=0;i<n;i++)
    {
        if(temp==no[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
            cout<<"yes it is present \n";
        else
            cout<<"no it is not present\n" ;
}
void binarysearch(int *no,int n)
{
    sorting(no,n);
    int temp,i,flag=0,c_b=0;
    cout<<"enter the no. u want to search :\n";
    cin>>temp;
    int lb=0,ub=n-1;

    while(ub>=lb)
    {
        if(temp>no[(ub+lb)/2])
        {
            lb=((ub+lb)/2)+1;
            c_b++;
        }
        else if(temp<no[(ub+lb)/2])
        {
            ub=((ub+lb)/2)-1;
            c_b++;
        }
        else if(temp==no[(ub+lb)/2])
        {
            c_b++;
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"yes"<<" couter="<<c_b<<"\n";
    else
        cout<<"no\n";

}
void sorting(int *no,int n)
{
    int i,j,c=0,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(no[j]<no[i])
            {
                temp=no[j];
                no[j]=no[i];
                no[i]=temp;
                c++;
            }
        }
    }
    cout<<"your array has been sorted in" <<c<<"steps\n";
}
void print(int *no,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<no[i]<<" ";
    }
    cout<<"\n";
}


int main()
{
    int n,i;
    cout<<"enter the length of array: ";
    cin>>n;
    cout<<"enter the elements of array";
    int no[100],temp;
    for(i=0;i<n;i++)
    {
        cin>>no[i];
    }
    cout<<"\n\n\n1 for insertion at beg.\n2 for insertion  in mid\n3 for insertion at end\n";
    cout<<"4 for deletion at end\n5 for deletion at mid\n6 for deleting an element from complete array\n7for linear search\n8 for binary search\n9 for sorting\n10 for print\n11for exit :";
    while(1)
    {
        int flag=0,c=0,lb,ub,c_b=0;
        cout<<"\nenter your choice :";
        int ch,j=0;
        cin>>ch;
        switch(ch)
        {
        case 1:
            insertion_beg(no,&n);
            break;
        case 2:
            insertion_mid(no,&n);
            break;
        case 3:
            insertion_end(no,&n);
            break;
        case 4:
            n=n-1;
            break;
        case 5:
            delete_mid(no,&n);
            break;
        case 6:
            delete_element(no,&n);
            break;
        case 7:
            linear_search(no,n);
            break;
        case 8:
            binarysearch(no,n);
            break;
        case 9:
            sorting(no,n);
            break;
        case 10:
            print(no,n);
            break;
        case 11:
            exit(0);
            break;
        default:
            cout<<"enter correct choice\n";


        }


    }
}
