#include<iostream>
using namespace std;
main()
{
    int m,n;
    cout<<"enter order of mat1\n";
    cin>>m>>n;
    int q,p;
    cout<<"enter order of mat2\n";
    cin>>q>>p;
    if(n!=q)
        cout<<"matrix are not multiplicable\n";
    else
    {int a[m][n],b[n][p],c[m][p],i,j,k;
    cout<<"enter elements of mat1\n";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        cin>>a[i][j];
    cout<<"enter elements of mat 2\n";
    for(i=0;i<n;i++)
        for(j=0;j<p;j++)
        cin>>b[i][j];
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
            }
        }
    }
    cout<<"required matrix is:\n";
    for(i=0;i<m;i++)
        {for(j=0;j<p;j++)
        {cout<<c[i][j]<<" ";}
        cout<<"\n";}
    }
}
