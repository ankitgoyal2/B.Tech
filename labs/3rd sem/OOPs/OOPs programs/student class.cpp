#include<iostream>
using namespace std;
class student
{
    char name[100];
    int age;
    int marks;
public:
    void setdata()
    {
        cout<<"enter name,age,marks of student\n";
        cin>>name>>age>>marks;
    }
    void display()
    {
       cout<<"name of student= "<<name<<"\nage of student= "<<age<<"\nmarks of student= "<<marks<<"\n";
    }
};
int main()
{
    student a;
    a.setdata();
    a.display();
}
