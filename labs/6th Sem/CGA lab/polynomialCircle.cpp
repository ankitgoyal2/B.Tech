#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
void setPixel(int x, int y, int h, int k)
{
    putpixel(x+h, y+k, 15);
    putpixel(x+h, -y+k, 15);
    putpixel(-x+h, -y+k, 15);
    putpixel(-x+h, y+k, 15);
    putpixel(y+h, x+k, 15);
    putpixel(y+h, -x+k, 15);
    putpixel(-y+h, -x+k, 15);
    putpixel(-y+h, x+k, 15);
}
main()
{
    int gd=0, gm,h,k,r;
    double x,y,x2;
    cout<<"enter center: ";
    cin>>h>>k;
    cout<<"enter radius: ";
    cin>>r;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    x=0,y=r;
    x2 = r/sqrt(2);
    while(x<=x2)
    {
        y = sqrt(r*r - x*x);
        setPixel(floor(x), floor(y), h,k);
        x += 1;
    }
    getch();
    closegraph();
    return 0;
}
