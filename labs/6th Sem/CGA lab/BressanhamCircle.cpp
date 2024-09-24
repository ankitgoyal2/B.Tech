#include <graphics.h>
#include <bits/stdc++.h>
#define color 15
using namespace std;
void eightWaySymmetricPlot(int xc,int yc,int x,int y)
{
    putpixel(x+xc,y+yc,color);
    putpixel(x+xc,-y+yc,color);
    putpixel(-x+xc,-y+yc,color);
    putpixel(-x+xc,y+yc,color);
    putpixel(y+xc,x+yc,color);
    putpixel(y+xc,-x+yc,color);
    putpixel(-y+xc,-x+yc,color);
    putpixel(-y+xc,x+yc,color);
}
void BressanhamCircle(int xc,int yc,int r)
{
    int x,y,d;
    x=0;
    y=r;
    d=3-2*r;
    eightWaySymmetricPlot(xc,yc,x,y);
    while(x<=y)
    {
        if(d<=0)
        {
            d=d+4*x+6;
        }
        else
        {
            d=d+4*x-4*y+10;
            y=y-1;
        }
        x=x+1;
        eightWaySymmetricPlot(xc,yc,x,y);
    }
}
int main()
{
    int gdriver = DETECT, gmode;
    int xc,yc,r;
    initgraph(&gdriver, &gmode, "");
    cout<<"Enter center point of circle : ";
    cin>>xc>>yc;
    cout<<"Enter the radius of circle : ";
    cin>>r;
    BressanhamCircle(xc,yc,r);
    getch();
    closegraph();
    return 0;
}
