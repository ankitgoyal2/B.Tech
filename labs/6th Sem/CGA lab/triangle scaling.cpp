#include<iostream>
#include<graphics.h>
using namespace std;
void findNewCoordinate(float s[][2], float p[][1])
{
    float temp[2][1] = { 0 };
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 1; j++)
            for (int k = 0; k < 2; k++)
                temp[i][j] += (s[i][k] * p[k][j]);
    p[0][0] = temp[0][0];
    p[1][0] = temp[1][0];
}
void scale(float x[], float y[], float sx, float sy)
{
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
    float s[2][2] = { sx, 0, 0, sy };
    float p[2][1];
    for (int i = 0; i < 3; i++)
    {
        p[0][0] = x[i];
        p[1][0] = y[i];
        findNewCoordinate(s, p);
        x[i] = p[0][0];
        y[i] = p[1][0];
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
   cout<<"enter scaling factors\n";
   cin>>sx>>sy;
   scale(x, y, sx,sy);
   getch();
   closegraph();
}
