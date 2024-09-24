/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT FRACTIONAL KNAPSACK PROBLEM
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 10/04/2019  */

#include<bits/stdc++.h>
using namespace std;
struct node
{
    float ratio,value,weight;
};
bool compare(node n1,node n2)
{
    return n1.ratio>n2.ratio;
}
int fractional_knapsack(node array[],int w,int size)
{
    sort(array,array+size,compare);
    int i=0,total_value=0,current_w=0;
    cout<<"weight of selected items are items are\n";
    while(i<size&&(current_w+array[i].weight)<=w)
    {
        current_w+=array[i].weight;
        total_value+=array[i].value;
        cout<<array[i].weight<<"\n";
        i++;
    }
    if(i<size&&w-current_w>0)
    {
        total_value+=(w-current_w)*array[i].ratio;
        cout<<array[i].weight<<"\n";
    }
    return total_value;
}
int main()
{
    int n,w;
    cout<<"enter no. of values and weight of knapsack\n";
    cin>>n>>w;
    node array[n];
    cout<<"enter values and weights\n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i].value>>array[i].weight;
        array[i].ratio=array[i].value/array[i].weight;
    }
    cout<<"total value "<<fractional_knapsack(array,w,n)<<"\n";
}
