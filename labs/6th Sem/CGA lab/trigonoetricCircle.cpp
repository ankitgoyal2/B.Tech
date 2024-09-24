#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
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
int main(){

    float xc,yc,p,x1,y1,y,r,x;
    float theta;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    cout<<"Enter the center of circle:";
    cin>>xc>>yc;
    cout<<"Enter radius of circle:";
    cin>>r;
    float i=0;
    while(i<=45){
        theta=(i*3.14)/180;
        x=(r*cos(theta));
        y=(r*sin(theta));
        eightSymmetricPointsPlot(xc,yc,x,y);
        i=i+0.01;
    }
    getch();
    closegraph();
    return 0;
}
