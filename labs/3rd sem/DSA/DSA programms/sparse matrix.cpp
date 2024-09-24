#include<iostream>
using namespace std;
int main()
{
    int i,t1,t2,j,k,x;
    cout<<"enter number of elements of matrix 1\n";
    cin>>t1;
    cout<<"enter number of elements of matrix 2\n";
    cin>>t2;
    int a1[t1+1],b1[t1+1],c1[t1+1];
    int a2[t2+1],b2[t2+1],c2[t2+1];
    cout<<"enter order of matrix 1\n";
    cin>>a1[0]>>b1[0];
    c1[0]=t1;
    cout<<"enter order of matrix 2\n";
    cin>>a2[0]>>b2[0];
    c2[0]=t2;
    int a3[a1[0]*b2[0]],b3[a1[0]*b2[0]],c3[a1[0]*b2[0]]={0};
    a3[0]=a1[0];
    b3[0]=b2[0];
    c3[0]=0;
    if(b1[0]==a2[0])
  {
    cout<<"enter row no.,column no.and value of element for matrix 1\n";
    for(i=1;i<=t1;i++)
        cin>>a1[i]>>b1[i]>>c1[i];
    cout<<"enter row no.,column no.and value of element for matrix 2\n";
    for(i=1;i<=t2;i++)
        cin>>a2[i]>>b2[i]>>c2[i];
    for(i=1;i<=t1;i++)
    {
        for(j=1;j<t1;j++)
        {
            if(a1[j+1]<a1[j])
            {
                k=a1[j];
                a1[j]=a1[j+1];
                a1[j+1]=k;
                k=b1[j];
                b1[j]=b1[j+1];
                b1[j+1]=k;
                k=c1[j];
                c1[j]=c1[j+1];
                c1[j+1]=k;
            }
            else if(a1[j+1]==a1[j])
            {
                if(b1[j+1]<b1[j])
                {
                    k=b1[j];
                    b1[j]=b1[j+1];
                    b1[j+1]=k;
                    k=c1[j];
                    c1[j]=c1[j+1];
                    c1[j+1]=k;
                }
            }
        }
    }
    for(i=1;i<=t2;i++)
    {
        for(j=1;j<t2;j++)
        {
            if(b2[j+1]<b2[j])
            {
                k=a2[j];
                a2[j]=a2[j+1];
                a2[j+1]=k;
                k=b2[j];
                b2[j]=b2[j+1];
                b2[j+1]=k;
                k=c2[j];
                c2[j]=c2[j+1];
                c2[j+1]=k;
            }
            else if(b2[j+1]==b2[j])
            {
                if(a2[j+1]<a2[j])
                {
                    k=a2[j];
                    a2[j]=a2[j+1];
                    a2[j+1]=k;
                    k=c2[j];
                    c2[j]=c2[j+1];
                    c2[j+1]=k;
                }
            }
        }
    }
  /*  cout<<"a1 b1 c1"<<endl;
    for(i=1;i<=t1;i++)
    {
         cout<<a1[i]<<" "<<b1[i]<<" "<<c1[i]<<endl;
    }
    cout<<endl;
    cout<<"a2 b2 c2"<<endl;
    for(i=1;i<=t2;i++)
    {
         cout<<a2[i]<<" "<<b2[i]<<" "<<c2[i]<<endl;
    }   */
    k=1;
    for(i=0;i<t1;i++)
    {
        for(j=0;j<t2;j++)
        {
            if(b1[i]==a2[j])
            {
                if(k>1&&a1[i]==a3[k-1]&&b1[j]==b3[k-1])
                {
                    k--;
                    c3[k]=c3[k]+c1[i]*c2[j];
                }
                else
                {
                    a3[k]=a1[i];
                    b3[k]=b2[j];
                    c3[k]=c1[i]*c2[j];
                }
                k++;
            }
        }
    }
    cout<<"a3 b3 c3"<<endl;
    for(i=1;i<=k-1;i++)
    {
         cout<<a3[i]<<" "<<b3[i]<<" "<<c3[i]<<endl;
    }
 /*   x=1;
    for(i=1;i<=a3[0];i++)
    {
        for(j=1;j<=b3[0];j++)
        {
            if(a3[x]==i&&b3[x]==j)
            {
                cout<<c3[x]<<" ";
                x++;
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }   */
  }
  else
    cout<<"multiplication is not possible\n";
}
