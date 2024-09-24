#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

vector<double> v[3];
void plot4pixels(int x,int y,int h,int k)
{
    putpixel(x+h,y+k,8);
    v[0].push_back(x+h);
    v[1].push_back(y+k);
    v[2].push_back(1);

    putpixel(x+h,-y+k,8);
    v[0].push_back(x+h);
    v[1].push_back(-y+k);
    v[2].push_back(1);

    putpixel(-x+h,y+k,8);
    v[0].push_back(-x+h);
    v[1].push_back(y+k);
    v[2].push_back(1);

    putpixel(-x+h,-y+k,8);
    v[0].push_back(-x+h);
    v[1].push_back(-y+k);
    v[2].push_back(1);
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

    float xc,yc,y,a,b,x,temp;
    double theta;

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    cout<<"Enter the center of ellipse:";
    cin>>xc>>yc;
    cout<<"Enter both axes of ellipse:";
    cin>>a>>b;
    cout<<"enter angle:";
    cin>>theta;
    double R_mat[3][3]={{cos(theta),-sin(theta),0},{sin(theta),cos(theta),0},{0,0,1}};
    midptellipse(a,b,xc,yc);
    vector<double> res[3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            temp=0;
            for(int k=0;k<3;k++)
            {
                temp+=R_mat[i][k]*v[k][j];
            }
            res[i].push_back(temp);
        }
    }
    for(int i=0;i<res[0].size();i++)
    {
        putpixel(res[0][i],res[1][i],8);
    }
    getch();
    closegraph();
    return 0;
}

