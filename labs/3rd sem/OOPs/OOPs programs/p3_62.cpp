#include<iostream>
using namespace std;
int c[20];
int m=0;
class set1
{
public:
    int a[20];
    int l;
    void create(void);
    void display(void);
};
void set1::create(void)
{
    cout<<"Enter length of set: ";
    cin>>l;
    cout<<"Enter data members"<<endl;
    for(int i=0;i<l;i++)
    {
        cout<<i+1<<" data element: ";
        cin>>a[i];
    }
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            if((a[i]!=a[j])&&(i!=j))
            {
                while(i!=l)
                {
                    m++;
                    c[m]=a[i];
                }
            }
        }
    }
}
void set1::display(void)
{
    cout<<endl<<"SET={";
    for(int i=0;i<m;i++)
        cout<<c[i]<<",";
    cout<<"}";
}
void uni(set1,set1);
void inter(set1,set1);
void set_min(set1,set1);
main()
{
    set1 s,t;
    int c;
    cout<<"choose operation:\n1.create and display\n2.intersection\n3.union\n";
    cin>>c;
    switch(c)
    {
    case 1:
        s.create();
        s.display();
        break;
    case 2:
        inter(s,t);
        break;
    case 3:
        uni(s,t);
        break;
    default:
        cout<<"DEFALUT:";
    }
}
void inter(set1 a, set1 b)
{
    a.create();
    b.create();
    int c[20];
    cout<<endl<<"set a"<<endl;;
    a.display();
    cout<<endl<<"set b:"<<endl;
    b.display();
    for(int i;i<a.l;i++)
    {
        for(int j=0;j<b.l;j++)
        {
            if(a.a[i]==b.a[j])
                c[i]=a.a[i];
        }
    }
    cout<<"intersection(a,b) = {";
    for(int i=0;i<a.l;i++)
    cout<<c[i]<<",";
    cout<<"}";
}

void uni(set1 a,set1 b)
{
    int u=0;
    a.create();
    b.create();
    int c[20],d[20],m=0;
    cout<<endl<<"set a"<<endl;;
    a.display();
    cout<<endl<<"set b:"<<endl;
    b.display();
    for(int i;i<a.l;i++)
    {
        for(int j=0;j<b.l;j++)
        {
            for(int k=0;k<a.l;k++)
                c[k]=a.a[i];
            for(int k=a.l;k<(a.l+b.l);k++)
                c[k]=b.a[j];
        }
    }
    for(int i=0;i<(a.l+b.l);i++)
    {
        for(int j=0;j<(a.l+b.l);j++)
        {
            if((c[i]!=c[j])&&(i!=j))

            {
                while(i!=a.l+b.l)
                {
                    u++;
                    d[u]=c[i];
                }
            }
        }
    }
    cout<<"union(a,b) = {";
    for(int i=0;i<u;i++)
    cout<<d[i]<<",";
    cout<<"}";
}
