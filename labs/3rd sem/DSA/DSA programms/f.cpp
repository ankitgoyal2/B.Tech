#include<iostream>
using namespace std;
class t2;
class t1
{
private:
    int h,m,s;
    public:
        t1()
        {
            h=m=s=0;
        }
        void setdata()
        {
            h=2;
            m=3;
            s=4;
        }
        int  geth(){return h;}
        int  getm(){return m;}
        void show()
        {
            cout<<h<<" "<<m<<" "<<s<<"\n";
        }
        friend int operator <=(t1,t2);
        t1(t2 );

};
class t2
{
    private:
    int h,m;
    public:
        t2()
        {
            h=m=0;
        }
        void setdata()
        {
            h=20;
            m=30;
        }
        void show()
        {
            cout<<h<<" "<<m<<"\n";
        }
        friend int operator <=(t1,t2);
        int  geth(){return h;}
        int  getm(){return m;}
        t2(t1 t)
        {
            h=t.geth();
            m=t.getm();
        }

};
int operator <=(t1 t,t2 ti)
{
    if(t.h+t.m<=ti.h+ti.m)
    {
        return 1;
    }
    return 0;
}
t1::t1(t2 ti)
{
    h=ti.geth();
    m=ti.getm();
    s=30;
}
int main()
{
    t1 t;
    t.setdata();
    t2 ti;
    ti.setdata();
    if(t<=ti)
    {
        cout<<"t is smaller\n";
    }
    else
    {
        cout<<"not smaller\n";
    }
    t=ti;
    t.show();
}
