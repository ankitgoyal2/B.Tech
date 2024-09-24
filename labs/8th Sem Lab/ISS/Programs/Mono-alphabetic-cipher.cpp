#include <bits/stdc++.h>
using namespace std;
int main()
{
    string EncryptionCipher = "qwertyuioplkjhgfdsazxcvbnm";
    string DecryptionCipher = "sxvqcponhmlkzyijadregwbuft";

    string s;
    int i;

    cout<<"Input the string :";
    cin>>s;
    int n = s.length();

    /// Encryption ==>
    string encrypted = s;
    for(i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
            encrypted[i] = EncryptionCipher[s[i]-'a'];
        else
            encrypted[i] = EncryptionCipher[s[i]-'A']-'a'+'A';
    }

    cout<<"Encrypted : "<<encrypted<<"\n";


    /// Decryption ==>
    string decrypted = encrypted;
    for(i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
            decrypted[i] = DecryptionCipher[encrypted[i]-'a'];
        else
            decrypted[i] = DecryptionCipher[encrypted[i]-'A']-'a'+'A';
    }

    cout<<"Decrypted : "<<decrypted;
}

