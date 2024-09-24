#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void findNewCoordinate(int s[][2], int p[][1])
{
	int temp[2][1] = { 0 };

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
			for (int k = 0; k < 2; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
}
void findNewCoordinate(float s[][2], int p[][1])
{
	float temp[2][1] = { 0 };

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
			for (int k = 0; k < 2; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
}
void findNewCoordinates(int s[][3], int p[][1])
{
	int temp[3][1] = { 0 };

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 1; j++)
			for (int k = 0; k < 3; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
}
void scale(int x[], int y[], int sx, int sy)
{
	line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[3], y[3]);
	line(x[3] , y[3] ,x[0] , y[0] );
    int s[2][2] = { sx, 0, 0, sy };
	int p[2][1];
	for (int i = 0; i <= 3; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];

		findNewCoordinate(s, p);

		x[i] = p[0][0];
		y[i] = p[1][0];
	}
	line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[3], y[3]);
	line(x[3] , y[3] , x[0] , y[0] );
}
void translate(int x[], int y[], int tx, int ty)
{
    int s[3][3] = { 1, 0, tx, 0 , 1 , ty , 0 , 0 , 1 };
	int p[3][1];
	int n=3;
	for (int i = 0; i <= 3; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];
        p[2][0] = 1;
		findNewCoordinates(s, p);
		x[i] = p[0][0];
		y[i] = p[1][0];
	}
	line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[3], y[3]);
	line(x[3] , y[3] , x[0] , y[0] );
}
void rotation(int x[] , int y[] , float theta)
{

    float c = cos(theta);
    float se = sin(theta);
    float s[2][2] = { c, -se, se, c };
	int p[2][1];
    for (int i = 0; i <= 3; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];

		findNewCoordinate(s, p);

		x[i] = p[0][0];
		y[i] = p[1][0];
	}
    line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[3], y[3]);
	line(x[3] , y[3] , x[0] , y[0] );
}
int main()
{
	int x[4] ;
	int y[4] ;
	cout<<"Enter the coordinates of four points\n";
	for(int i=0; i<4;i++)
        cin>>x[i]>>y[i];
	int sx , sy;
	int gd, gm;
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm," ");
    line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[3], y[3]);
	line(x[3] , y[3] ,x[0] , y[0] );
	float theta;
	int tx , ty;
	cout<<"1. For translation\n";
	cout<<"2. For Scaling\n";
	cout<<"3. For rotation\n";
	int ch;
	cout<<"enter your choice\n";
	cin>>ch;
	switch(ch)
	{

    case 1:
        {
            cout<<"Enter the x and y distance for translation\n";
            cin>>tx>>ty;
            translate(x , y , tx, ty);
            break;
        }
    case 2:
        {
            cout<<"Enter the x and y scaling factor\n";
            cin>>sx>>sy;
            scale(x , y, sx , sy);
            break;
        }
    case 3:
        {
            cout<<"Enter the angle for rotation in radian\n";
            cin>>theta;
            rotation(x , y , theta);
            break;
        }
    default :
        cout<<"enter a valid choice\n";
	}
	getch();

	return 0;
}
