#include<iostream>
using namespace std;
#define n 4
void multiply(int a[n][n],int b[n][n])
{
    int i,j,k,c[n][n],sum,co=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {sum=0;
            for(k=0;k<n;k++)
            {sum+=a[i][k]*b[k][j];}
            if(sum!=0)
                co++;
            c[i][j]=sum;
        }

    }
    cout<<"\n\nresulting sparse matrix after multiplication is:\n";
    int arr[co+1][3];k=1;arr[0][0]=arr[0][1]=n;arr[0][2]=co;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(c[i][j]!=0)
            {
                arr[k][0]=i;
                arr[k][1]=j;
                arr[k][2]=c[i][j];
                k++;
            }
        }

    }
    for(i=0;i<co+1;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<arr[i][j]<<"\t";
        }cout<<endl;
    }



}
int main()
{
    int m,i,j,p,q,e,r,t;
    int a[n][n]={0},b[n][n]={0};
    cout<<"enter the number of non zero elements of matrix 1,2 respectively:";
    cin>>p>>q;
    cout<<"matrix 1\n";
    for(i=0;i<p;i++)
    {
        cout<<"enter the row number,column no and value of non zero elements no"<<i+1<<":";
        cin>>e>>r>>t;
        a[e][r]=t;
    }cout<<"matrix 2\n";
    for(i=0;i<q;i++)
    {
        cout<<"enter the row number,column no and value of non zero elements no"<<i+1<<":";
        cin>>e>>r>>t;
        b[e][r]=t;
    }

    multiply(a,b);
}
