#include<iostream>
#include<string.h>
using namespace std;

class staff
{
protected:
    int code;
    char name[20];
};

class teacher:public staff
{
protected:
    int publication;
    char subject[20];
};

class typist:public staff
{
protected:
    int speed;
};

class officer:public staff
{
protected:
    char grade;
};

class education:public teacher,public officer
{
protected:
    char degree1[20];
    char degree2[20];
public:
    void getdata_t(int c,char n[],int p,char s[],char d[])
    {
        teacher::code=c;
        strcpy(teacher::name,n);
        publication=p;
        strcpy(subject,s);
        strcpy(degree1,d);
    }
    void getdata_o(int c,char n[],char g,char d[])
    {
        officer::code=c;
        strcpy(officer::name,n);
        grade=g;
        strcpy(degree2,d);
    }
    void display_t()
    {
        cout<<"\ndetails for teachers";
        cout<<"\nname = "<<teacher::name<<"  code = "<<teacher::code;
        cout<<"  publication = "<<publication<<"  subject = "<<subject;
        cout<<"  degree = "<<degree1<<"\n";
    }
    void display_o()
    {
         cout<<"\ndetails for officers";
        cout<<"\nname = "<<officer::name<<"  code = "<<officer::code;
        cout<<"  grade = "<<grade;
        cout<<"  degree = "<<degree2<<"\n";
    }
};

class regular:public typist
{
public:
    void getdata(int c,char n[],int sp)
    {
        code=c;
        strcpy(name,n);
        speed=sp;
    }
    void display()
    {
        cout<<"\ndetails for regular typist";
        cout<<"\nname = "<<name<<"  code = "<<code<<"  speed = "<<speed<<"\n";
    }
};

class casual:public typist
{
protected:
    int wages;
public:
    void getdata(int c,char n[],int sp,int w)
    {
        code=c;
        strcpy(name,n);
        speed=sp;
        wages=w;
    }
    void display()
    {
        cout<<"\ndetails for casual typist";
        cout<<"\nname = "<<name<<"  code = "<<code<<"  speed = "<<speed<<"  wages = "<<wages<<"\n";
    }
};

int main()
{
    education e;
    regular r;
    casual c;
    int a,b,d;
    char s[20],n[20],g,x[20];
    cout<<"details for teachers\n";
    cout<<"enter code and name\n";
    cin>>a>>n;
    cout<<"enter subject and publication and degree\n";
    cin>>s>>b>>x;
    e.getdata_t(a,n,b,s,x);

    cout<<"\ndetails for officers\n";
    cout<<"enter code and name\n";
    cin>>a>>n;
    cout<<"enter grade and degree\n";
    cin>>g>>x;
    e.getdata_o(a,n,g,x);

    cout<<"\ndetails for regular typist\n";
    cout<<"enter code and name\n";
    cin>>a>>n;
    cout<<"enter speed\n";
    cin>>b;
    r.getdata(a,n,b);

    cout<<"\ndetails for casual typist\n";
    cout<<"enter code and name\n";
    cin>>a>>n;
    cout<<"enter speed and wages\n";
    cin>>b>>d;
    c.getdata(a,n,b,d);

    e.display_t();
    e.display_o();
    r.display();
    c.display();
}





