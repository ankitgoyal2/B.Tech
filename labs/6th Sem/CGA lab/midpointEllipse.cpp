#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;

void plot4pixels(int x,int y,int h,int k)
{
    putpixel(x+h,y+k,8);
    putpixel(x+h,-y+k,8);
    putpixel(-x+h,y+k,8);
    putpixel(-x+h,-y+k,8);
}
void midptellipse(int a, int b, int xc, int yc)
{
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = b;

	d1 = (b * b) - (a * a * b) + (0.25 * a * a);
	dx = 2 * b * b * x;
	dy = 2 * a * a * y;
	while (dx < dy)
	{

		plot4pixels(x,y,xc,yc);
		if (d1 < 0)
		{
			x++;
			dx = dx + (2 * b * b);
			d1 = d1 + dx + (b * b);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * b * b);
			dy = dy - (2 * a * a);
			d1 = d1 + dx - dy + (b * b);
		}
	}
	d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) +
		((a * a) * ((y - 1) * (y - 1))) -
		(a * a * b * b);
	while (y >= 0)
	{
		plot4pixels(x,y,xc,yc);
		if (d2 > 0)
		{
			y--;
			dy = dy - (2 * a * a);
			d2 = d2 + (a * a) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * b * b);
			dy = dy - (2 * a * a);
			d2 = d2 + dx - dy + (a * a);
		}
	}
}

int main(){

    float xc,yc,y,a,b,x;
    float theta;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    cout<<"Enter the center of ellipse:";
    cin>>xc>>yc;
    cout<<"Enter both axes of ellipse:";
    cin>>a>>b;
    midptellipse(a,b,xc,yc);
    getch();
    closegraph();
    return 0;
}

