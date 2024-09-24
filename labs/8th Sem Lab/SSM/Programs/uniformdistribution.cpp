#include <random>
#include <iostream>
#include <iomanip>
#include <array>
#include <map>
using namespace std;


int main() {
    int choice;
    cout << "Enter \n1. For uniform distribution and \n2. To exit\n";
    cin>>choice;
    if(choice==1){
        const int nrolls = 500;
        const int nstars = 95;
        const int nintervals = 10;

        default_random_engine generator;
        uniform_real_distribution<double> distribution(0.0, 1.0);

        
        cout << "Random number generated : ";
        for (int i = 0; i < nrolls; ++i)
        {
            double number = distribution(generator);
           // ++p[int(nintervals * number)];
            cout << number << " ";
        }
        // cout << endl;
        // cout << "uniform_real_distribution (0.0,1.0):" << endl;
        // cout << fixed;
        // cout.precision(1);

        // for (int i = 0; i < nintervals; ++i)
        // {
        //     cout << float(i) / nintervals << "-" << float(i + 1) / nintervals << ": ";
        //     cout << string(p[i] * nstars / nrolls, '*') << endl;
        // }
    }
    else{
          //exit();

    }
}
