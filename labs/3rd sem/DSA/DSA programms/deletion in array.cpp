#include <iostream>
using namespace std;
int main()
{
   int a[10], pos, i, n, item;
   cout<<"Enter number of elements in array\n";
   cin>>n;
   cout<<"enter elements of array";
   for (i = 0;i<n;i++)
      cin>>a[i];
   cout<<"enter the position of item to delete";
      cin>>pos;
   for (i =pos;i<n;i++)
      a[i]=a[i+1];
   for (i=0;i<n-1;i++)
      cout<<a[i]<<" ";
   return 0;
}
