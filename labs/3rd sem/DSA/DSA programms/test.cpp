#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream out;
    char data[32];
    out.open("text",ios::out);
    cout<<"enter content: ";
    cin.getline(data,32);
    out<<data;
    out.close();
    ifstream in;
    in.open("text",ios::in);
    cout<<"enter content:";
    int r;
    while(in.eof()==0)
    {
        in>>data;
        cout<<data;
        r=in.tellg();
        cout<<r;
    }
}
