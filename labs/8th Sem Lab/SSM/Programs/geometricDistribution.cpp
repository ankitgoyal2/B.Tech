#include <iostream>
#include <random>
using namespace std;
int main(void) {
  const int nrolls = 10000; // number of experiments
  const int nstars = 100;   // maximum number of stars to distribute

  default_random_engine generator;
  geometric_distribution <int> distribution (0.3);
  int p[10] = {};
  for (int i=0; i < nrolls; ++i) {
    int number = distribution (generator);
    if (number < 10) {
		++p[number];
	}
  }
  cout << "geometric_distribution (0.3):" << endl;
  for (int i = 0; i < 10; ++i)
    cout << i << ": " << string(p[i] * nstars / nrolls, '*') << endl;
  return 0;
}