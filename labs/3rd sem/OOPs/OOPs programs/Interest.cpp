#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

void Interest(float,float,float=0.04);
void Interest2(float,float=2,float=0.04);
void Interest3(float=10000,float=4,float=0.04);

int main()
{
    Interest(3000,5);
    Interest2(5000);
    Interest3();
    return 0;

}

void Interest(float p, float t, float r)
{
    float i = p*r*t;
    cout<<i;
}
void Interest2(float p,float t,float r)
{
    float i = p*r*t;
    cout<<"\n"<<i;
}
void Interest3(float p,float t,float r)
{
    float i = p*r*t;
    cout<<"\n"<<i;
}
