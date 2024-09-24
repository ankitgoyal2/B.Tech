#include<bits/stdc++.h>
using namespace std;
int main(){
	float xa=0,ya=0,xb=0,yb=10,xc=0,yc=20,xd=0,yd=30;
	float dab,dbc,dcd,ddd;
	float t,del;
	t=0,del=0.002;
	float va=30,vb=25,vc=20,vd=15;
	dab=sqrt(pow(xa-xb,2)+pow(ya-yb,2));
	dbc=sqrt(pow(xb-xc,2)+pow(yb-yc,2));
	dcd=sqrt(pow(xc-xd,2)+pow(yc-yd,2));
	ddd=sqrt(pow(xd-30,2)+pow(yd-50,2));
	cout<<"xa\tya\txb\tyb\txc\tyc\txd\tyd\n";
	while(t<=2.0){
		xa=xa+va*del*(xb-xa)/dab;
		ya=ya+va*del*(yb-ya)/dab;
		xb=xb+vb*del*(xc-xb)/dbc;
		yb=yb+vb*del*(yc-yb)/dbc;
		xc=xc+vc*del*(xd-xc)/dcd;
		yc=yc+vc*del*(yd-yc)/dcd;
		xd=xd+vd*del*(30-xd)/ddd;
		yd=yd+vd*del*(50-yd)/ddd;
		dab=sqrt(pow(xa-xb,2)+pow(ya-yb,2));
	    dbc=sqrt(pow(xb-xc,2)+pow(yb-yc,2));
	    dcd=sqrt(pow(xc-xd,2)+pow(yc-yd,2));
	    ddd=sqrt(pow(xd-30,2)+pow(yd-50,2));
	    t+=del;
	    cout<<xa<<"\t"<<ya<<"\t"<<xb<<"\t"<<yb<<"\t"<<xc<<"\t"<<yc<<"\t"<<xd<<"\t"<<yd<<"\n";
	    if(dab<=0.005){
	    	cout<<"A hit B\t time="<<t<<"\n";

	    	break;
		}
		if(dbc<=0.005){
			cout<<"B hit C\t time="<<t<<"\n";break;
		}
		if(dcd<=0.005){
			cout<<"C hit D\t time="<<t<<"\n";break;
		}
		if(ddd<=0.005)
        {
            cout<<"D hit\t time="<<t<<"\n";break;
        }
	}
}
