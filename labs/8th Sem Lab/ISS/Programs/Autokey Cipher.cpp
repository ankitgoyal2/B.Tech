#include <bits/stdc++.h>
using namespace std;
string lowercase(string s)
{
    for(int i = 0;i<s.length();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i]-'A'+'a';
    }
    return s;

}
int main()
{
    string plaintext;
   string key;

    cout<<"Enter Plaintext : ";
    cin>>plaintext;

    cout<<"Enter key : ";
    cin>>key;
    cout<<"\n";
    plaintext = lowercase(plaintext);
    key = lowercase(key);

    int n = plaintext.size();
    if(n>key.length())      key += plaintext;

    /// Encryption

    for(int i=0;i<plaintext.length();i++)
        plaintext[i] = 'a' + ((plaintext[i]-'a') + (key[i]-'a'))%26;

    cout<<"Encryption String : "<<plaintext<<"\n";

   for(int i=0;i<plaintext.length();i++)
        plaintext[i] = 'a' + (plaintext[i]- key[i]+26)%26;

   cout<<"Decryption String : "<<plaintext;
}

