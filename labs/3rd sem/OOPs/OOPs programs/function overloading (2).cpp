#include<iostream>
#include<conio.h>
using namespace std;
void display (int);
void display (float);
void display(int,float);

int main()
{
int a = 5;
float b=3.5f;
display(a);
display(b);
display(a,b);
return 0;
}
void display(int var)
{
    cout<<"integer number:"<<var<<endl;
}

void display (float var)
{
    cout<<"float number:"<<var <<endl;
}

void display(int var1,float var2)
{

cout<<"integer number :"<<var1;
cout<<"float number :"<<var2;
}

