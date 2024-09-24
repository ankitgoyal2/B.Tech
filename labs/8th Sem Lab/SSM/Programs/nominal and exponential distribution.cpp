#include <bits/stdc++.h>
using namespace std;
void normal()
{
    int i, j, m, nn;
    float t, sum, x, mue, sigma;

    cout << "Enter the value of mue - ";
    cin >> mue;
    cout << "Enter the value of sigma - ";
    cin >> sigma;
    cout << "Number of random variables needed - ";
    cin >> nn;

    for (m = 1; m <= nn; m++)
    {
        sum = 0;
        for (i = 1; i <= 12; i++)
        {
            x = float(rand()) / float(RAND_MAX);
            sum = sum + x;
        }
        t = mue + sigma * (sum - 6.);
        cout << t << "  ";
    }
}
void expo()
{
    int i, j, k, m, nn;
    double lambda;
    cout << " Enter the value of Lambda ";
    cin >> lambda;
    cout << "Number of random variables needed - ";
    cin >> nn;
    for (m = 1; m <= nn; m++)
    {
        double u = float(rand()) / float(RAND_MAX);
        double x = log(1 - u) / (-lambda);
        cout << x << "  ";
    }
}
int main()
{
    int c;
    while (true)
    {
        cout << "Press 1 for Normal Distribution " << endl;
        cout << "Press 2 for Exponential Distribution " << endl;
        cin >> c;

        if (c == 1)
            normal();
        else
            expo();
        cout << endl;
    }
    return 0;
}
