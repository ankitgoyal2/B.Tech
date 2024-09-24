#include<bits/stdc++.h>
using namespace std;

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

    int n;
    cout<<"Enter the value of n(size of each block) : ";
    cin>>n;
    string plain, cipher="";
    cout<<"Enter the plain text : ";
    cin>>plain;
    string key;
    cout<<"Enter the key for vigenere cipher :";
    cin>>key;
    key = generateKey(key,n);
    cout<<"key "<<key<<"\n";
    int blocks;
    if(plain.length()%n!=0)
        {
            int k= (plain.length()/n) * n;
            int g= plain.length()-k;
            g=n-g;

            for(int i=0; i<g; ++i)
                plain.append("z");
        }

    blocks= plain.length()/n;
    for(int i=0;i<blocks; ++i)
    {    string tp= plain.substr(i*n, i*n+n);

         string ci= cipherText(tp,key);
         cipher.append(ci);
    }

    cout<<"The Cipher text is: "<<cipher<<"\n";


}
