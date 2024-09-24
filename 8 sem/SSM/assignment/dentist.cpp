#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> serviceTime = {{"filling", 45}, {"crown", 60}, {"cleaning", 15}, {"extraction", 45}, {"check-up", 15}};
    vector<int> numbers{40, 82, 11, 34, 25, 66, 17, 79};
    int curTime = 0, maxTime = 0;
    int idle = 0;
    int wait = 0;
    for (int i = 0; i < 8; i++)
    {
        if (curTime > maxTime)
        {
            idle += (curTime - maxTime);
            maxTime = curTime;
        }
        wait += (maxTime - curTime);
        curTime += 30;
        string type = "";
        if (numbers[i] < 40)
            type = "filling";
        else if (numbers[i] < 55)
            type = "crown";
        else if (numbers[i] < 70)
            type = "cleaning";
        else if (numbers[i] < 80)
            type = "extraction";
        else
            type = "check-up";
        maxTime += serviceTime[type];
    }
    cout << "Dentist remains idle for " << idle << " minutes\n";
    cout << "Average waiting time for patients is :" << ((float)wait / 8.0) << " minutes\n";
    return 0;
}
