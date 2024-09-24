#include<bits/stdc++.h>
using namespace std;
main()
{

    int x,j,nn,k;
    float lemda,cp,fact,prob,y,mean;

    cout<<"enter value of lemda: ";
    cin>>lemda;
    cout<<"enter no. of variables to be generated: ";
    cin>>nn;

    mean=lemda;
    for(j=1;j<nn;j++)
    {

        x=0;fact=1;
        cp=0;
        y=rand()/32768.0;
        while(y>cp)
        {
            prob = pow(2.718282, -mean)*pow(mean,x)/fact;
            cp+=prob;
            x=x+1;
            fact*=x;
        }
        cout<<x<<" ";
    }
}
