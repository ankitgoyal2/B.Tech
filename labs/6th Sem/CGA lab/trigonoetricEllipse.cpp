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
int main(){
    float xc,yc,y,a,b,x;
    float theta;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    cout<<"Enter the center of ellipse:";
    cin>>xc>>yc;
    cout<<"Enter both axes of ellipse:";
    cin>>a>>b;
    float i=0;
    while(i<=90){
        theta=(i*3.14)/180;
        x=(a*cos(theta));
        y=(b*sin(theta));
        plot4pixels(x,y,xc,yc);
        i=i+0.01;
    }
    getch();
    closegraph();
    return 0;
}

