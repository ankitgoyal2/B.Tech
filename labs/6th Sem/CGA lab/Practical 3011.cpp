#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
#define color 15
void drawCircle(int xc,int yc,int x,int y)
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
    drawCircle(xc,yc,x,y);
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
        drawCircle(xc,yc,x,y);
    }
}
int main()
{
    int gd = DETECT ,gm, i;
    float x, y,dx,dy,steps;
    int x0, x1, y0, y1;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    x0=120;
    y0=120;
    x1=120;
    y1=320;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    if(dx>=dy)
           {
        steps = dx;
    }
    else
           {
        steps = dy;
    }
    dx = dx/steps;
    dy = dy/steps;
    x = x0;
    y = y0;
    i = 1;
    while(i<= steps)
    {
        putpixel(x, y, WHITE);
        x += dx;
        y += dy;
        i=i+1;
    }
    BressanhamCircle(240,220,100);
    getch();
    closegraph();
    return 0;
}
