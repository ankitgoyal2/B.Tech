#include<bits/stdc++.h>
using namespace std;
vector<int>c1,c2;
bool isPrime(int n)
{
    if (n<=1)
        return false;
    if (n<=3)
        return true;
    if (n%2==0||n%3==0)
        return false;
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y >> 1;
        x = (x*x) % p;
    }
    return res;
}
void findPrimefactors(unordered_set<int> &s, int n)
{
    while (n%2 == 0)
    {
        s.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }
    if (n > 2)
        s.insert(n);
}
int findPrimitive(int n)
{
    unordered_set<int> s;
    if (isPrime(n)==false)
        return -1;
    int phi = n-1;
    findPrimefactors(s, phi);
    for (int r=2; r<=phi; r++)
    {
        bool flag = false;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (power(r, phi/(*it), n) == 1)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return r;
    }
    return -1;
}
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
string decryption(vector<int>c1, vector<int>c2,int d,int p)
{
    string decrypted="";
    int len=c1.size();
    for(int i=0; i<len; ++i)
    {
        int inv= modInverse(pow(c1[i],d),p);
//cout<<"Inverse : "<<inv<<"\n";
        int a= ((c2[i]%p)* (inv%p))%p;
//cout<<"a = "<<a<<"\n";
        char c=(a+32);
        decrypted+=c;
    }
    return decrypted;
}
void encryption(string plaintext, int e1,int e2, int p)
{
    int len= plaintext.length();
    int ran= ((rand() % (p-1 + 1 - 1)) + 1);
    cout<<"random : "<<ran<<"\n";
    for(int i=0; i<len; ++i)
    {
        int a= power(e1,ran,p);
        c1.push_back(a);
//cout<<"int plain :"<<int(plaintext[i])<<"\n";
        int b= int((plaintext[i])-32)%p;
        int c= power(e2,ran,p);
        a=b*c;
        a=a%p;
        c2.push_back(a);
    }
}
int main()
{
    string plaintext;
    int p,d,e1,e2;
    cout<<"Key generation \n";
    cout<<"Enter Prime number (p>94) :";
    cin>>p;
    cout<<"Enter d (such that 1<=d<=p-2): ";
    cin>>d;
    e1=findPrimitive(p);
    e2= power(e1,d,p);
    cout<<"Public key : ("<<e1<<", "<<e2<<", "<<p<<" )\n";
    cout<<"Private key : "<<d<<"\n";
    cout<<"Enter plain text : ";
    cin>>plaintext;
    encryption(plaintext,e1,e2,p);
    cout<<"Encrypted message:\n";
    for(int i=0; i<c1.size(); ++i)
    {
        cout<<"( "<<c1[i]<<", "<<c2[i]<<" ) ";
    }
    cout<<"\n";
    string decrypted = decryption(c1,c2,d,p);
    cout<<"Decrypted message : "<<plaintext<<"\n";
}
