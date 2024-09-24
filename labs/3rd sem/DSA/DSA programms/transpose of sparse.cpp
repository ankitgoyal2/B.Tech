#include<iostream>
using namespace std;
struct sparse
{
    int r,c,v;
};
void getinput(sparse *s,int x)
{
    cout<<"enter the order of matrix :\n";
    int n,m;
    cin>>n>>m;
    s[0].r=n;s[0].c=m;s[0].v=x;
    cout<<"enter row ,column and value of matrix :\n";
    int i;
    for(i=1;i<=x;i++)
    {
        cin>>s[i].r>>s[i].c>>s[i].v;
    }
}
void transpose(sparse *s)
{
    int i;
    for(i=0;i<=s[0].v;i++)
    {
        int temp=s[i].r;
        s[i].r=s[i].c;
        s[i].c=temp;
    }
}
void print(sparse *s)
{
    int i,j,k;
    for(i=0;i<s[0].r;i++)
    {
        for(j=0;j<s[0].c;j++)
        {
           int flag=0;
            for(k=1;k<=s[0].v;k++)
            {
                if(i==s[k].r && j==s[k].c)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                cout<<s[k].v<<" ";
            else
                cout<<0<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    cout<<"enter the no. of non zero elements: ";
    int n;
    cin>>n;
    sparse s[n+1];
    getinput(s,n);
    cout<<"before transpose :\n";
    print(s);
    transpose(s);
    cout<<"after transpose :\n";
    cout<<"\n";
    print(s);

}
