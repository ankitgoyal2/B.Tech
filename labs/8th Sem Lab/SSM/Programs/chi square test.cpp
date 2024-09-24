
#include <bits/stdc++.h>
using namespace std;
int main()
{
    float chi;
    int random[20];
    int s1,s2,mod,i=2;
    cout<<"Enter s1 :";
    cin>>s1;
    cout<<"Enter s2 : ";
    cin>>s2;
    cout<<"Enter modulus : ";
    cin>>mod;

    /// Generating Random numbers
    random[0] = (s1+s2)%mod;
    random[1] = (s2+random[0])%mod;
    for(i=2;i<20;i++)
        random[i] = (random[i-1] + random[i-2])%mod;

    int ctsize = ceil(mod/10);
    int ct[20];
    memset(ct,0,sizeof(ct));

    cout<<"Enter value of chi-square at alpha(0.5) : ";
    cin>>chi;
    for(i=0;i<20;i++)
    {
        if(random[i]%ctsize==0)
            random[i] = random[i]-1;
        ct[random[i]/ctsize + 1]++;
    }
    cout<<"The hypothesis value of random numbers generated is :    ";
    for(i=0;i<ctsize;i++)
        cout<<ct[i]<<" ";
    cout<<endl;

    float chisq  = 0;
    for(i=0;i<ctsize;i++)
    {
        chisq += ((ctsize - (float)ct[i])*(ctsize - (float)ct[i]))/ctsize;
    }
    cout<<"The calculated chi sqaure value : "<<chisq<<"\n";
    if(chisq<chi)
        cout<<"The hypothesis is true: The numbers are uniformly distributed";
    else
        cout<<"The hypothesis is rejected.";

}
