#include<iostream>
#include<graphics.h>
using namespace std;
void scale(float x[], float y[], float sx, float sy)
{
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    for(int i=0;i<3;i++)
    {
        x[i]+=sx;
        y[i]+=sy;
    }
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
}
int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   float x[3],y[3],sx,sy;
   cout<<"enter the vertexes\n";
   cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
   cout<<"enter translation factors\n";
   cin>>sx>>sy;
   scale(x, y, sx,sy);
   getch();
   closegraph();
}

