#include<bits/stdc++.h>
using namespace std;

int max1(int a, int b){
	if (a>b)
        return a;
    else
        return b;
}

int main(){

    int i,j,k,p1[20],p2[20],e1,e2,dep[20][20];
    cout<<"enter the events : ";
    cin>>e1>>e2;

    for(i=0;i<e1;i++)
    p1[i]=i+1;

    for(i=0;i<e2;i++)
        p2[i]=i+1;
    cout<<"enter the dependency matrix:"<<endl;
    cout<<"\t enter 1 if e1->e2 \n\t enter -1, if e2->e1 \n\t else enter 0 \n"<<endl;
    cout<<"\t";
    for(i=0;i<e2;i++)
        cout<<"e2"<<i+1<<"\t";
    cout<<endl;
    for(i=0;i<e1;i++){
        cout<<"e1"<<i+1<<"\t";
        for(j=0;j<e2;j++)
            cin>>dep[i][j];
    }
    for(i=0;i<e1;i++){
        for(j=0;j<e2;j++){
            if(dep[i][j]==1){
                p2[j]=max1(p2[j],p1[i]+1);
                for(k=j;k<e2;k++)
                    p2[k+1]=p2[k]+1;
            }
            if(dep[i][j]==-1){
                p1[i]=max1(p1[i],p2[j]+1);
                for(k=i;k<e1;k++)
                    p2[k+1]=p1[k]+1;
            }
        }
    }
    cout<<"P1 : ";
    for(i=0;i<e1;i++){
        cout<<p1[i]<<" ";
    }
    cout<<endl;
    cout<<"P2 : ";
    for(j=0;j<e2;j++)
        cout<<p2[j]<<" ";
    return 0 ;
}
