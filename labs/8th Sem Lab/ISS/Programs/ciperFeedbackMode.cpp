#include<bits/stdc++.h>
using namespace std;


string xor_operation(string a, string b)
{
    string ans="";
    int n=a.length();
    for(int i=0; i<n; ++i)
    {
     char k= ((a[i]^b[i])%26  )+'a';
     ans+=k;
    }

    return ans;

}
string generateKey(string key, int x)
{


    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == x)
            break;
        key.push_back(key[i]);
    }
    return key;
}

string cipherText(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {

        char x = (str[i] + key[i]) %26;


        x += 'a';

        cipher_text.push_back(x);
    }
    return cipher_text;
}



int main()
{

    int r;
    cout<<"Enter the value of r(size of each block) : ";
    cin>>r;
    string plain, cipher="", S;
    cout<<"Enter the plain text : ";
    cin>>plain;
    string key;
    cout<<"Enter the key for vigenere cipher : ";
    cin>>key;
    cout<<"Enter the initial value of shift register : ";
    cin>>S;
    int n=S.length();
    key = generateKey(key,n);
    cout<<"\nKey : "<<key;

    int blocks;
    if(plain.length()%r!=0)
        {
            int k= (plain.length()/r) * r;
            int g= plain.length()-k;
            g=r-g;

            for(int i=0; i<g; ++i)
                plain.append("z");
        }

    blocks= plain.length()/r;
    cout<<"\nBlocks : "<<blocks;

    for(int i=0;i<blocks; ++i)
    {
         string cip=cipherText(S,key);
         cip= cip.substr(0,r);
         string tp= plain.substr(i*r, i*r+r);
         tp= xor_operation(tp,cip);
         S=S.substr(r, n);
         S.append(tp);
         cout<<"\nCipher : "<<tp<<" new S : "<<S<<"\n";
         cipher.append(tp);
    }

    cout<<"The Cipher text is: "<<cipher<<"\n";


}

