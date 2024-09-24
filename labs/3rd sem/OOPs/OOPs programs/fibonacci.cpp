#include<iostream>
using namespace std;
int main(){

cout<<"enter a number"<<endl;
long long int n;
cin>>n;
long long int r;
 long long int a=-1;
 long long int b=1;
for(int i=0;i<n;i++){
    r=a+b;
    a=b;
    b=r;
    cout<<r<<" ";
}
return 0;
}
