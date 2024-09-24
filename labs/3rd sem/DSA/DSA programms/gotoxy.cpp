#include<iostream>
#include<windows.h>
using namespace std;
void gotoxy(int a,int b)
{
    COORD c;
    c.X=a;
    c.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main()
{
    gotoxy(20,20);
    cout<<"hello\n";
}
