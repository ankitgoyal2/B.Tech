/*  PROGRAM NO. 3
PROGRAM NAME = MERGE SORT
ROLL NO. = 17103011
DATE = 16/01/2019   */

#include<iostream>
using namespace std;
int counter;
void merge(int arr[],int lower,int mid,int uper)
{
    int size=uper-lower+1;
    int size_left=mid-lower+1;
    int size_right=uper-mid;
    int array_left[size_left+1],array_right[size_right+1];
    int i,j,k;
    for(i=0;i<size_left;i++)
        array_left[i]=arr[lower+i];
    for(j=0;j<size_right;j++)
        array_right[j]=arr[mid+1+j];
    array_left[i]=INT_MAX;
    array_right[j]=INT_MAX;
    i=j=0;
    for(k=0;k<size;k++)
    {
        counter++;
        if(array_left[i]<=array_right[j])
        {
            arr[lower+k]=array_left[i];
            i++;
        }
        else
        {
            arr[lower+k]=array_right[j];
            j++;
        }
    }
}
void merge_sort(int arr[],int l_bound,int u_bound)
{
    if(l_bound<u_bound)
    {
        int mid=(l_bound+u_bound)/2;
        merge_sort(arr,l_bound,mid);
        merge_sort(arr,mid+1,u_bound);
        merge(arr,l_bound,mid,u_bound);
    }
}
int main()
{
    int testcases;
    cout<<"enter no. of testcases\n";
    cin>>testcases;
    while(testcases--)
    {
        int size,i=0,j,flag=0;
        cout<<"enter size of array\n";
        cin>>size;
        int arr[size];
        cout<<"enter array\n";
        cin>>arr[i];
        i++;
        if(arr[0]>=0)
        {
            flag=1;
           while(i<size)
          {
              cin>>arr[i];
              if(arr[i]<0)
                flag=3;
              i++;
          }
        }
        else
        {
            flag=2;
            while(i<size)
            {
                cin>>arr[i];
                if(arr[i]>=0)
                    flag=3;
                i++;
            }
        }
        if(flag==3)
            cout<<"invalid input\n";
        else
        {
            counter=0;
            merge_sort(arr,0,size-1);
            i=0;
            cout<<"sorted array is \n";
            while(i<size)
            {
                cout<<arr[i]<<" ";
                i++;
            }
            cout<<"\nno. of comparison = "<<counter;
            cout<<"\n";
        }
    }
}
