#include<iostream>
using namespace std;
class string1
{
    char a[100];
public:
    void setstring()
    {
        cout<<"enter string\n";
        cin>>a;
    }
    void addstring(string1 x,string1 y)
    {
        int i=0,j=0;
        while(x.a[i]!='\0')
        {
            a[i]=x.a[i];
            i++;
        }
        while(1)
        {
            a[i]=y.a[j];
            i++;
            j++;
            if(y.a[j]=='\0')
            {
                a[i]='\0';
                break;
            }
        }
        cout<<"Added string is "<<a<<"\n";
    }
};
int main()
{
    string1 c,d,e;
    c.setstring();
    d.setstring();
    e.addstring(c,d);
}
