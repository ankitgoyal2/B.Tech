#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
inline void gotoxy(int a,int b)
{
    COORD c;
    c.X=a;
    c.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
class s
{
    int i=0,j=0,k=0;
    char c;
    int head=4;
    char arr[100]={'\0'};
public:
    s()
    {
        arr[0]='#';
        arr[1]='#';
        arr[2]='#';
        arr[3]='#';
        arr[4]='<';
    }
    void box()
{
    int i=20;

    while(i!=70)
    {
        gotoxy(i,10);
        cout<<"#";
        gotoxy(i,19);
        cout<<"#";
        i++;
    }
    i=11;
    while(i!=19)
    {
        gotoxy(20,i);
        cout<<"!";
        gotoxy(69,i);
        cout<<"!\n";
        i++;
    }
}
int move_s(int i,int j)
{
    i=i+1;
    return i ;
}
void print()
{
    int i=0;
    while(i!=head)
    {
        cout<<arr[i];
        i++;
    }
}
};



int main()
{

    s snk;
     snk.box();
    gotoxy(20,13);
    int i=20;
    while(i!=69)
    {
        snk.box();
        gotoxy(i,13);
        Sleep(1000);
        snk.print();
        system("cls");
        i++;

    }
}
