#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> serviceTime;
    serviceTime.insert({"filling",45});
    serviceTime.insert({"crown",60});
    serviceTime.insert({"cleaning",15});
    serviceTime.insert({"extraction",45});
    serviceTime.insert({"check-up",15});

    vector<int> numbers;
    numbers.push_back(40);
    numbers.push_back(82);
    numbers.push_back(11);
    numbers.push_back(34);
    numbers.push_back(25);
    numbers.push_back(66);
    numbers.push_back(17);
    numbers.push_back(79);

    int curTime=0,maxTime=0;
    int idle=0;
    int wait=0;
    for(int i=0;i<8;i++)
    {
        if(curTime>maxTime)
        {
            idle+=(curTime-maxTime);
            maxTime=curTime;
        }
            wait+=(maxTime-curTime);
            curTime+=30;
            string type="";
            if(numbers[i]<40)
                type="filling";
            else if(numbers[i]<55)
                type="crown";
            else if(numbers[i]<70)
                type="cleaning";
            else if(numbers[i]<80)
                type="extraction";
            else
                type="check-up";
            maxTime+=serviceTime[type];
    }
    cout<<"Dentist remains idle for "<<idle<<" minutes\n";
    cout<<"Average waiting time for patients is :"<<((float)wait/8.0)<<" minutes\n";
    return 0;
}
