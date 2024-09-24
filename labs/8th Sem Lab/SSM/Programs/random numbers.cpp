#include<bits/stdc++.h>
using namespace std;

long long  a[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
int middleSquareNumber(int numb, int dig)
{
    long long int sqn = numb * numb, next_num = 0;
    int trim = (dig / 2);
    sqn = sqn / a[trim];
    for (int i = 0; i < dig; i++)
    {
        next_num += (sqn % (a[trim])) * (a[i]);
        sqn = sqn / 10;
    }
    return next_num;
}
void midsq()
{
   cout<<"Enter the seed value :";
   int seed;
   cin>>seed;
   int dig;
   cout<<"Enter the number of digits :";
   cin>>dig;
   int n;
   cout<<"Enter the number of random numbers you want to generate: ";
   cin>>n;
   cout<<"The random numbers are: ";
   cout<<seed<<", ";
   int ni=seed;
   for(int i=1; i<n; ++i)
   {
         ni = middleSquareNumber(ni,dig);
         cout<<ni<<", ";
   }
   cout<<"\n";


}
void residue()
{
   int a,c,M,r;
   cout<<"Enter the value of 'a', 'c' and 'M': ";
   cin>>a>>c>>M;
   cout<<"Enter the number of random numbers you want :";
   int n;
   cin>>n;
   cout<<"Enter the first random number: ";
   cin>>r;
   cout<<"The random numbers are: ";
   cout<<r<<", ";
   int rd=r;
   for(int i=1; i<n; ++i)
   {
       r= (a*rd+ c)%M;
       rd=r;
       cout<<r<<", ";
   }
   cout<<"\n";

}
void arithmeticCong()
{

int n,a,b,m;
cout<<"Enter the number of random numbers you want to generate :";
cin>>n;
cout<<"Enter the seed values: ";
cin>>a>>b;
cout<<"Enter the value of M";
cin>>m;
int r;
cout<<"The random numbers generated are :";
for(int i=0; i<n; ++i)
{
    r=(a+b)%m;
    b=a;
    a=r;
    cout<<r<<", ";
}
cout<<"\n";
}
int main()
{

    int choice;
    do{
    cout<<"Enter the choice of Algorithm for generating random numbers\n1.Mid square method\n2.Residue Method\n3.Arithmetic Congruential Method\n4.Exit\n";
    cin>>choice;

    switch(choice)
    {
    case 1: midsq();
        break;
    case 2: residue();
        break;
    case 3: arithmeticCong();
        break;
    case 4:
        break;
    default:
        cout<<"Wrong choice\n";
        break;
    }
    }while(choice<4);
}

