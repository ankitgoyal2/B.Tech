#include<bits/stdc++.h>
using namespace std;
struct node
{
    int s,e;
};
bool compare(node n1,node n2)
{
    if(n1.e==n2.e)
        return n1.s<n2.s;
    else
        return n1.e<n2.e;
}
int asp(node array[],int n)
{
    int m[n][n],i,j,k,l,value;
    sort(array,array+n,compare);
   /* i=0;
    while(i<n)
    {
        cout<<array[i].s<<" ";
        cout<<array[i].e<<"\n";
        i++;
    }  */
    for(l=1;l<n;l++)
    {
        for(i=0;i<n-l;i++)
        {
            j=i+l;
            m[i][j]=0;
            for(k=i+1;k<j;k++)
            {
                if(array[i].e<=array[k].s&&array[k].e<=array[j].s)
                {
                    value=m[i][k]+m[k][j]+1;
                    if(value>m[i][j])
                        m[i][j]=value;
                }
            }

        }
    }
    return m[0][n-1];
}
int main()
{
    int number,count;
    cout<<"enter no. of activities\n";
    cin>>number;
    node array[number+2];
    cout<<"enter start and end time\n";
    int i=0;
    array[i].s=array[i].e=0;
    i=1;
    while(i<=number)
    {
        cin>>array[i].s;
        cin>>array[i].e;
        i++;
    }
    array[i].s=array[i].e=INT_MAX;
    count=asp(array,number+2);
    cout<<count<<"\n";
}
