#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void drawline(int x1, int y1, int x2, int y2)
{
    int dx,dy;

    int x,y,x_end,y_end;

    dx = (x2-x1);
    dy = (y2-y1);

     float m = dy/dx;

     dx = abs(dx);
     dy = abs(dy);



    if(abs(m)<=1 && m>0)
    {
        cout<<1;
        int p = 2*dy-dx;
        if(x1>x2)
        {
            x = x2;
            x_end = x1;
            y = y2;
        }
        else
        {
            x = x1;
            x_end = x2;
            y = y1;
        }

        while(x<=x_end)
        {
            putpixel(x,y,WHITE);
            x = x+1;

            if(p<0)
            {
                p = p + 2*dy;
            }
            else
            {
                y = y+1;
                p = p + 2*(dy-dx);
            }
        }
    }
    else if(abs(m)<=1 && m<0)
    {
        cout<<2;
        int p = 2*dy-dx;
        if(x1>x2)
        {
            x = x2;
            x_end = x1;
            y = y2;
        }
        else
        {
            x = x1;
            x_end = x2;
            y = y1;
        }

        while(x<=x_end)
        {
            putpixel(x,y,WHITE);
            x = x+1;

            if(p<0)
            {
                p = p + 2*dy;
            }
            else
            {
                y = y-1;
                p = p + 2*(dy-dx);
            }
        }
    }
    else if(abs(m)>=1 && m>0)
    {
        cout<<3;
        int p = 2*dx-dy;
        if(y1>y2)
        {
            y = y2;
            y_end = y1;
            x= x2;
        }
        else
        {
            x = x1;
            y_end = y2;
            y = y1;
        }

        while(y<=y_end)
        {
            putpixel(x,y,WHITE);
            y = y+1;

            if(p<0)
            {
                p = p + 2*dx;
            }
            else
            {
                x= x+1;
                p = p + 2*(dx-dy);
            }
        }
    }
    else
    {
        cout<<4;
        int p = 2*dx-dy;
        if(y1>y2)
        {
            y = y2;
            y_end = y1;
            x= x2;
        }
        else
        {
            x = x1;
            y_end = y2;
            y = y1;
        }

        while(y<=y_end)
        {
            putpixel(x,y,WHITE);
            y = y+1;

            if(p<0)
            {
                p = p + 2*dx;
            }
            else
            {
                x= x-1;
                p = p + 2*(dx-dy);
            }
        }
    }

}
int main()
{
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;

    cout<<"enter two points:(x1,y1,x2,y2) ";
    cin>>x0>>y0;
    cin>>x1>>y1;
    initgraph(&gdriver, &gmode, "");
    drawline(x0, y0, x1, y1);
    getch();
    return 0;
}
