/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT LONGEST COMMON SUBSEQUENCE
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 13/03/2019  */

#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2,int length1,int length2)
{
    int m[length1+1][length2+1];
    int i,j;
    for(i=0;i<=length1;i++)
    {
        for(j=0;j<=length2;j++)
        {
            if(i==0||j==0)
                m[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                m[i][j]=1+m[i-1][j-1];
            else
                m[i][j]=max(m[i-1][j],m[i][j-1]);
        }
    }
    return m[length1][length2];
}
int main()
{
    string s1,s2;
    cout<<"enter string 1\n";
    cin>>s1;
    cout<<"enter string 2\n";
    cin>>s2;
    int a=lcs(s1,s2,s1.length(),s2.length());
    cout<<"length of LCS is "<<a<<"\n";
}
