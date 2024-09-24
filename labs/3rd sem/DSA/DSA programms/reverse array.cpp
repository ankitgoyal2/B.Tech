#include<iostream>
using namespace std;
int main()
{
	int n, i, a[10];
	cout<<"Enter total number of elements ";
	cin>>n;
	cout<<"enter elements of array ";
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n/2;i++)
	{
        a[i]=a[i]+a[n-1-i];
        a[n-1-i]=a[i]-a[n-1-i];
        a[i]=a[i]-a[n-1-i];
	}
	cout<<"reversed array";
	for(i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
