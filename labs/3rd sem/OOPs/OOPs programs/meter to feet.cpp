#include<iostream>
using namespace std;
class feet;
class meter
{
    float a,b;
public:
    void set_data(float x,float y)
    {
        a=x;
        b=y;
    }
    friend void add(meter&,feet&);
};
class feet
{
    float a,b;
public:
    void set_data(float x,float y)
    {
        a=x;
        b=y;
    }
    friend void add(meter&,feet&);
};

void add(meter &j,feet &k)
{
    float m;
    int n,c;
    m=((j.a*100)+j.b)*(0.3937)+12*k.a+k.b;
    n=m;
    c=n%12;
    n=n-c;
    n=n/12;
    m=m-n*12;
    cout<<"\nin feet and inches\n";
    cout<<n<<" feet  "<<m<<" inches\n";
    m=((k.a*12)+k.b)*2.54+100*j.a+j.b;
    n=m;
    c=n%100;
    n=n-c;
    n=n/100;
    m=m-n*100;
    cout<<"\nin meter and centimeters\n";
    cout<<n<<" meter  "<<m<<" centimeter\n";
}

int main()
{
    meter a;
    feet b;
    float x,y;
    cout<<"enter meter and centimeter\n";
    cin>>x>>y;
    a.set_data(x,y);
    cout<<"enter feet and inches\n";
    cin>>x>>y;
    b.set_data(x,y);
    add(a,b);
}
