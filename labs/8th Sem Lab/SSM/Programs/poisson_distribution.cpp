#include <iostream>
#include <random>

using namespace std;

int main()
{
  const int nrolls = 10000; // number of experiments
  const int nstars = 100;   // maximum number of stars to distribute

  default_random_engine generator;
  poisson_distribution<int> distribution(4.1);

  int p[10]={};

  for (int i=0; i<nrolls; ++i) {
    int number = distribution(generator);
    if (number<10) ++p[number];
  }

  cout << "poisson_distribution (mean=4.1):" << endl;
  for (int i=0; i<10; ++i)
    cout << i << ": " << string(p[i]*nstars/nrolls,'*') << endl;

  return 0;
}
