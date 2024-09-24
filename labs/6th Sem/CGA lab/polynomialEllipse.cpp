#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;
void plot4pixels(int x,int y,int h,int k)
{
    putpixel(x+h,y+k,8);
    putpixel(x+h,-y+k,8);
    putpixel(-x+h,y+k,8);
    putpixel(-x+h,-y+k,8);
}
int main()
{
    int x,y,r,i,h,k,a,b;
    cout<<"Enter the center of ellipse:";
    cin>>h>>k;
    cout<<"Enter both axes of ellipse:";
    cin>>a>>b;
    x=0;
    y=b;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    setbkcolor(WHITE);
    while(x<a)
    {
        plot4pixels(x,y,h,k);
        x++;
        y=b*sqrt(((a*a)-(x*x*1.0))/(a*a));
    }
    plot4pixels(x,y,h,k);
    getch();
    return 0;
}

