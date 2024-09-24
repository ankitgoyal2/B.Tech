#include<bits/stdc++.h>
using namespace std;
main()
{

    int x,j,nn,m,s;
    float p,r;

    cout<<"enter value of p: ";
    cin>>p;
    cout<<"enter no. of variables to be generated: ";
    cin>>nn;
    for(j=1;j<nn;j++)
    {

        x=0;s=0;
        while(s<1)
        {
            r=rand()/32768.0;
            if(r<p)
                s=s+1;
            x=x+1;
        }
        cout<<x<<" ";
    }
}
