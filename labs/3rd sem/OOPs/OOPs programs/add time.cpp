#include<iostream>
using namespace std;
class time
{
    int h=0,m=0,s=0;
public:
    void settime()
    {
        cout<<"enter hours,minutes and seconds \n";
        cin>>h>>m>>s;
    }
    void addtime(time x,time y)
    {
        s=x.s+y.s;
        m=x.m+y.m;
        h=x.h+y.h;
        if(s>=60)
        {
            s=s%60;
            m++;
        }
        if(m>=60)
        {
            m=m%60;
            h++;
        }
       cout<<"total time is "<<h<<" hours "<<m<<" minutes "<<s<<" seconds \n";
    }
};
int main()
{
    time t1,t2,t3;
    t1.settime();
    t2.settime();
    t3.addtime(t1,t2);
}

