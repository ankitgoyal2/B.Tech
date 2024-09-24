#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,x,i, left=0,right=n-1;
    cout<<"enter no. of elements and enter no. u want to search ";
    cin>>n>>x;
    int arr[n];
    cout<<"enter elements in sorted order : ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    while(left<right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==x)
        {
            cout<<"no. is present"<<mid+1<<"\n";
            return 0;
        }
        else if(arr[mid]>x)
            right=mid-1;
        else
            left=mid+1;
    }
    cout<<"no. is not present\n";
}
