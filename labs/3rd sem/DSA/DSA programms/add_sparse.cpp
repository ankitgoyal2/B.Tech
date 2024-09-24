#include<iostream>
using namespace std;
int main()
{
int a[6][3]={5,5,5,0,0,23,1,2,16,2,4,9,4,2,20,4,4,2};
int b[5][3]={5,5,4,0,3,6,1,2,9,2,3,7,4,3,12};
int l=1,i=1,j=1,x=a[0][2],y=b[0][2],k,u=0;
int m=10,c[m][3];
while(i<=x&&j<=y+1){
        if(a[i][0]<b[j][0])
        {
            for(k=0;k<3;k++)
                c[l][k]=a[i][k];
            i++;l++;
        }
        else if(a[i][0]>b[j][0])
        {
            for(k=0;k<3;k++)
                c[l][k]=b[j][k];
            j++;l++;
        }
        else if(a[i][1]<b[j][1])
        {
            for(k=0;k<3;k++)
                c[l][k]=a[i][k];
                i++;l++;
        }
        else if(a[i][1]>b[j][1])
        {
            for(k=0;k<3;k++)
                c[l][k]=b[j][k];
            j++;l++;
        }
        else
        {
            for(k=0;k<3;k++)
                c[l][k]=a[i][k];
                c[l][2]+=b[j][2];
                m--;j++;i++;l++;
        }


        c[0][0]=c[0][1]=5;c[0][2]=m-1;
}cout<<"initial matrix=\n";
for(x=0;x<6;x++)
{
    for(y=0;y<3;y++)
    {cout<<a[x][y]<<"\t";
    }cout<<endl;
}cout<<"----------------------------"<<endl;
for(x=0;x<5;x++)
{
    for(y=0;y<3;y++)
    {cout<<b[x][y]<<"\t";
    }cout<<endl;
}cout<<"\nfinal matrix after summation:\n";
for(x=0;x<m;x++)
{
    for(y=0;y<3;y++)
    {cout<<c[x][y]<<"\t";
    }cout<<endl;
}

}
