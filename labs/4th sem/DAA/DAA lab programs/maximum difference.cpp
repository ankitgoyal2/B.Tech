#include<bits/stdc++.h>
using namespace std;
pair<int,int> max_difference(int array[],int size)
{
    int i,index=0;
    pair <int,int> p;
    int diff=INT_MIN;
    i=1;
    while(i<size)
    {
        if(array[i]-array[index]>diff)
        {
            p.first=index;
            p.second=i;
            diff=array[i]-array[index];
        }
        if(array[i]<array[index])
            index=i;
        i++;
    }
    return p;
}
int main()
{
    int size,i;
    cout<<"enter size of array\n";
    cin>>size;
    i=0;
    int array[size];
    while(i<size)
    {
        cin>>array[i];
        i++;
    }
    pair <int,int> p;
    p=max_difference(array,size);
    cout<<p.first+1<<" "<<p.second+1<<"\n";
}
