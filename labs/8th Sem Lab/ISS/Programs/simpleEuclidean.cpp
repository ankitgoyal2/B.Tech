#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}


int main()
{
	int a,b;
	cout<<"enter two numbers\n";
	cin>>a>>b;
	cout << "GCD is " << gcd(a, b);

}
