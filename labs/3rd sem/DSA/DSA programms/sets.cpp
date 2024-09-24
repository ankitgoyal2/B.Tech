#include<iostream>
using namespace std;
class sets
{
    int a[100];
    int length;
public:
    void create(int k)
    {
        length=k;
    }
    void setdata()
    {
        int i=0;
        while(i!=length)
        {
            cout<<"enter number\n";
            cin>>a[i];
            i++;
        }
    }
    int is_member(int k)
    {
        int i=0,j=0;
        while(1)
        {
            if(a[i]==k)
            {
                j=1;
                break;
            }
            if(i==length-1)
            break;
            i++;
        }
        if(j)
            return 1;
        else
            return 0;

    }
    int len()
    {
        return length;

    int member(int i)
    {
        return a[i];
    }

    void add_member(int i)
    {
        length++;
        a[length]=i;
    }
    friend sets uni(sets,sets);
    friend sets in(sets,sets);

};
sets uni(sets a,sets b)
{
    int i=0,j;
    j=b.len;
    while(i!=j)
    {
        if(a.is_member(b.member(i)))
        {
            a.add_member(b.member(i));
        }
        i++;

    }
    return a;
}
int main()
{
    sets x,y,z;
    int i,j;
    cout<<"enter length of set\n";
    cin>>i;
    x.create(i);
    x.setdata();
    cout<<"enter length of set\n";
    cin>>i;
    y.create(i);
    y.setdata();
    z=uni(x,y);
}
