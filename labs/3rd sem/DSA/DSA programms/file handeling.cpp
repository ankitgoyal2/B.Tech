#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("ankit");
    fout<<"hey there i am ankit";
    fout.close();
}
