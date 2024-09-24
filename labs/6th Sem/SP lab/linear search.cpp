#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,x,i;
    cout<<"enter no. of elements and element to be search\n";
    cin>>n>>x;
    int arr[n];
    cout<<"enter elements: ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            cout<<"no. is present\n";
            break;
        }
    }
    if(i==n)
        cout<<"no. is not present\n";
}
