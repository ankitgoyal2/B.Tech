#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter size of the array\n";
    cin>>n;
    int arr[n];
    cout<<"enter the array\n";
    int i,j;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int min,max;
    min=max=arr[0];
    i=1;
    while(i<n)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
        i++;
    }
    int range=max-min+1;
    int temp[range]={0},output[n];
    for(i=0;i<n;i++)
    {
        temp[arr[i]-min]++;
    }
    for(i=1;i<range;i++)
    {
        temp[i]+=temp[i-1];
    }
    for(i=0;i<n;i++)
    {
        output[temp[arr[i]-min]-1]=arr[i];
        temp[arr[i]-min]--;
    }
    cout<<"sorted array is \n";
    for(i=0;i<n;i++)
    {
        cout<<output[i]<<" ";
    }

}
