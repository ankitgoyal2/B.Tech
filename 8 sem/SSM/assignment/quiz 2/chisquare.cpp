#include<bits/stdc++.h>
using namespace std;

main()
{
    vector<int>num;
    int n;
    cout<<"Enter the number of random numbers : ";
    cin>>n;
    int a;
    cout<<"Enter random numbers: ";
    for(int i=0; i<n; ++i)
    {
        cin>>a;
        num.push_back(a);
    }

    int classes[10]={0};

    for( int i=0; i<n ; ++i)
    {

        if(num[i]<=10 && num[i]>0)
            classes[0]++;
        else if( num[i]>10 && num[i]<=20)
            classes[1]++;
        else if( num[i]>20 && num[i]<=30)
            classes[2]++;
         else if( num[i]>30 && num[i]<=40)
            classes[3]++;
         else if( num[i]>40 && num[i]<=50)
            classes[4]++;
         else if( num[i]>50 && num[i]<=60)
            classes[5]++;
         else if( num[i]>60 && num[i]<=70)
            classes[6]++;
         else if( num[i]>70 && num[i]<=80)
            classes[7]++;
         else if( num[i]>80 && num[i]<=90)
            classes[8]++;
         else if( num[i]>90 && num[i]<=100)
            classes[9]++;

    }

    int k;
    cout<<"Enter the expected value : ";
    cin>>k;

    cout<<"Freq. of each class : ";
    for( int i=0; i<10; ++i)
        cout<<classes[i]<<" ";
    cout<<"\n";

    float ans=0.0;
    for(int i=0; i<10;++i)
    {

        ans+=(classes[i]-k)*(classes[i]-k);

    }

    ans=ans/k;

    cout<<"For 95% accuracy, chi value is 16.9\n";
    cout<<"Chi value of this is : "<<ans;
    if(ans<16.9)
        cout<<"\nYes, uniformally distributed ";
    else
        cout<<"\nNot uniformally distributed ";




}
