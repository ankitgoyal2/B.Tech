#include<iostream>
#include<bits/stdc++.h>
#include<graphics.h>
#define color 15

using namespace std;

void eightSymmetricPointsPlot(int xc,int yc,int x,int y)
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
void midPointCircle(int xc,int yc,int r)
{
    int x,y,d;
    x=0;
    y=r;
    d=1-r;
    eightSymmetricPointsPlot(xc,yc,x,y);
    while(x<=y)
    {
        if(d<=0)
        {
            d=d+2*x+10;
        }
        else
        {
            d=d+2*x-2*y+5;
            y=y-1;
        }
        x=x+1;
        eightSymmetricPointsPlot(xc,yc,x,y);
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
	midPointCircle(xc, yc, r);
	getch();
	return 0;
}
