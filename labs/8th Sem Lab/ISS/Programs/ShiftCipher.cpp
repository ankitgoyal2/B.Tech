#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int k;
    int i;

    cout<<"Input the string :";
    cin>>s;
    cout<<"Input cipher key : ";
    cin>>k;
    int n = s.length();

    /// Encryption ==>
    string encrypted = s;
    for(i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
            encrypted[i] = (s[i]-'a'+k)%26 + 'a';
        else
            encrypted[i] = (s[i]-'A'+k)%26 + 'A';
    }

    cout<<"Encrypted : "<<encrypted<<"\n";


    /// Decryption ==>
    string decrypted = encrypted;
    for(i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
            decrypted[i] = (encrypted[i]-'a'-k+26)%26 + 'a';
        else
            decrypted[i] = (encrypted[i]-'A'-k+26)%26 + 'A';
    }

    cout<<"Decrypted : "<<decrypted;
}
