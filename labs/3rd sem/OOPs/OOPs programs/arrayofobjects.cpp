#include<iostream>
#include<conio.h>
using namespace std;

class student

{
char name[20] ;
int roll ;
float per;
public:
void getdata();
void display();
};
void student::getdata()
{
  cout<<"enter the details";
  cin>>name>>roll>>per;
}
void student::display()
{
    cout<<name<<"t"<<roll<<"t"<< per<<endl;
}
int main ()


{
student s[10];
int i,n;
cout<<"enter how many students";
cin>>n;
for (i=0;i<n;i++)
s[i].getdata();
cout<<"roll\t name\t  per\n";
s[i].display();
getch();
return 0 ;
}
