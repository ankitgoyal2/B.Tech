#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int gd = DETECT ,gm, i;
    float x, y,dx,dy,steps;
    int x0, x1, y0, y1;
    initgraph(&gd, &gm, "");

    cout<<"enter two points:(x1,y1,x2,y2) ";
    cin>>x0>>y0>>x1>>y1;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    if(dx>=dy)
        steps = dx;
    else
        steps = dy;
    dx = dx/steps;
    dy = dy/steps;
    x = x0;
    y = y0;
    i = 1;
    while(i<= steps)
    {
        putpixel(x, y, 15);
        x += dx;
        y += dy;
        i=i+1;
    }
    getch();
    closegraph();
    return 0;
}
