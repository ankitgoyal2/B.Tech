#include<bits/stdc++.h>
using namespace std;
void merge_arr(int arr[],int beg,int mid,int en)
{
    int size_l=mid-beg+1;
    int size_r=en-mid;
    int arr_l[size_l+1],arr_r[size_r+1];
    int i;
    for(i=0;i<size_l;i++)
    {
        arr_l[i]=arr[beg+i];
    }
    arr_l[i]=INT_MAX;
    for(i=0;i<size_r;i++)
    {
        arr_r[i]=arr[mid+1+i];
    }
    arr_r[i]=INT_MAX;
    int j=0,k=0;
    i=0;
    while(i<en-beg+1)
    {
        if(arr_l[j]<=arr_r[k])
        {
            arr[i+beg]=arr_l[j];
            j++;
        }
        else
        {
            arr[i+beg]=arr_r[k];
            k++;
        }
        i++;
    }
}
void merge_sort(int arr[],int beg,int en)
{
    if(beg<en)
    {
        int mid=beg+(en-beg)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,en);
        merge_arr(arr,beg,mid,en);
    }
}

int main()
{
    int n;
    cout<<"enter no of elements\n";
    cin>>n;
    cout<<"enter array\n";
    int arr[n];
    int i=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    cout<<"sorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
