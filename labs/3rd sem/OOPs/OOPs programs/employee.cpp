#include<iostream>
using namespace std;
class employee
{
    char name[20];
    int age,salary,id;
public:
    void getdata()
    {
        cout<<"enter employee name,age,salary and id\n";
        cin>>name>>age>>salary>>id;
    }
    void putdata()
    {
        cout<<"\nName="<<name<<"\nAge="<<age<<"\nsalary="<<salary<<"\nId="<<id<<endl;
    }
};
int main()
{
    int i,a;
    cout<<"enter number of employees\n";
    cin>>i;
    employee manager[i],clerk[i],lecturer[i];
    cout<<"enter details for managers\n";
    a=0;
    while(a!=i)
    {
        manager[a].getdata();
        manager[a].putdata();
        a++;
    }
    cout<<"enter details for clerks\n";
    a=0;
    while(a!=i)
    {
        clerk[a].getdata();
        clerk[a].putdata();
        a++;
    }
    cout<<"enter details for lecturers\n";
    a=0;
    while(a!=i)
    {
        lecturer[a].getdata();
        lecturer[a].putdata();
        a++;
    }


}
