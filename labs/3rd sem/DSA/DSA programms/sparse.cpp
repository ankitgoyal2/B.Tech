#include<iostream>
using namespace std;
int main()
{
    int i,t,j,k;
    cout<<"enter number of elements\n";
    cin>>t;
    int a[t+1],b[t+1],c[t+1];
    cout<<"enter order of matrix\n";
    cin>>a[0]>>b[0];
    c[0]=t;
    cout<<"enter row no.,column no.and value of element\n";
    for(i=1;i<=t;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(i=1;i<=t;i++)
    {
        for(j=1;j<t;j++)
        {
            if(a[j+1]<a[j])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
                k=b[j];
                b[j]=b[j+1];
                b[j+1]=k;
                k=c[j];
                c[j]=c[j+1];
                c[j+1]=k;
            }
            else if(a[j+1]==a[j])
            {
                if(b[j+1]<b[j])
                {
                    k=b[j];
                    b[j]=b[j+1];
                    b[j+1]=k;
                    k=c[j];
                    c[j]=c[j+1];
                    c[j+1]=k;
                }
            }
        }
    }
    k=1;
    for(i=1;i<=a[0];i++)
    {
        for(j=1;j<=b[0];j++)
        {
            if(a[k]==i&&b[k]==j)
            {
                cout<<c[k]<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl<<"transpose matrix \n";
    for(i=1;i<=t;i++)
    {
        for(j=1;j<t;j++)
        {
            if(b[j+1]<b[j])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
                k=b[j];
                b[j]=b[j+1];
                b[j+1]=k;
                k=c[j];
                c[j]=c[j+1];
                c[j+1]=k;
            }
            else if(b[j+1]==b[j])
            {
                if(a[j+1]<a[j])
                {
                    k=a[j];
                    a[j]=a[j+1];
                    a[j+1]=k;
                    k=c[j];
                    c[j]=c[j+1];
                    c[j+1]=k;
                }
            }
        }
    }
    k=1;
    for(i=1;i<=b[0];i++)
    {
        for(j=1;j<=a[0];j++)
        {
            if(a[k]==j&&b[k]==i)
            {
                cout<<c[k]<<" ";
                k++;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
