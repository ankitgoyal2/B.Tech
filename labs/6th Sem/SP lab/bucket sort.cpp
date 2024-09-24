#include<bits/stdc++.h>
using namespace std;
void bucketSort(float arr[], int n)
{
	vector<float> b[n];
	for (int i=0; i<n; i++)
	{
        int bi = n*arr[i];
        b[bi].push_back(arr[i]);
	}
	for (int i=0; i<n; i++)
        sort(b[i].begin(), b[i].end());
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
void printArray(float arr[] , int n, int div)
{
	for (int i=0; i<n; i++)
	cout << arr[i]*div << " ";
	cout<<endl;
}
int main()
{
    int n;
    cout<<"enter the number of elements in the array\n";
    cin>>n;
    float arr[n];
    cout<<"enter the elements\n";
    for(int i=0; i<n;i++)
        cin>>arr[i];

    int max1 = *max_element(arr,arr+n);
    int div = 1;
    while(max1>0)
    {
        div= div*10;
        max1=max1/10;
    }
    for(int i=0;i<n;i++)
        arr[i]=arr[i]/div;
	bucketSort(arr, n);
	cout << "Sorted array is \n";
	printArray(arr , n, div);
	return 0;
}
