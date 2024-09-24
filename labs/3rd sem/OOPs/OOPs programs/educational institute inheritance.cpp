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
public:
    void getdata(int c,char n[],int p,char s[20])
    {
        code=c;
        strcpy(name,n);
        publication=p;
        strcpy(subject,s);
    }
    void display()
    {
        cout<<"\ndetails for teachers";
        cout<<"\nname = "<<name<<"  code = "<<code<<"  publication = "<<publication<<"  subject = "<<subject<<"\n";
    }
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
public:
    void getdata(int c,char n[],char g)
    {
        code=c;
        strcpy(name,n);
        grade=g;
    }
    void display()
    {
         cout<<"\ndetails for officers";
        cout<<"\nname = "<<name<<"  code = "<<code<<"  grade = "<<grade<<"\n";
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
    teacher t;
    officer o;
    regular r;
    casual c;
    int a,b,d;
    char s[20],n[20],g;
    cout<<"details for teachers\n";
    cout<<"enter code and name\n";
    cin>>a>>n;
    cout<<"enter subject and publication\n";
    cin>>s>>b;
    t.getdata(a,n,b,s);

    cout<<"\ndetails for officers\n";
    cout<<"enter code and name\n";
    cin>>a>>n;
    cout<<"enter grade\n";
    cin>>g;
    o.getdata(a,n,g);

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

    t.display();
    o.display();
    r.display();
    c.display();
}




