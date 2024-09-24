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
    int key1, key2;

    cout<<"Enter Plaintext : ";
    cin>>plaintext;

    cout<<"Enter key(multiplicative and additive ) : ";
    cin>>key1>>key2;
    cout<<"\n";
    plaintext = lowercase(plaintext);

    /// Encryption
    for(int i = 0;i<plaintext.length();i++)
    {
        plaintext[i] = 'a' + ((plaintext[i]-'a')*key1+key2)%26;
    }

    cout<<"Encrypted String : "<<plaintext<<"\n";


    /// Decryption
    /// For inverse of key1, we need to find some other key
    /// (key1*x)mod26=(1)mod26
    int i = 1;
    while((key1*i)%26!=1)
        i++;
    int key3 = i;
    for(int i = 0;i<plaintext.length();i++)
    {
        plaintext[i] = 'a'+(((plaintext[i]-'a'-key2+26)%26)*key3)%26;
    }

    cout<<"Decrypted String : "<<plaintext;

    cout<<"\n";
}

