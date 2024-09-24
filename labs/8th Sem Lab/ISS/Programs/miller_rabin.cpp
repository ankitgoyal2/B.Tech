#include <bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y, int p)
{
	int res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
bool miillerTest(int d, int n)
{

	int a = 2 + rand() % (n - 4);
	int x = power(a, d, n);
	if (x == 1 || x == n - 1)
		return true;
	while (d != n - 1)
	{
		x = (x * x) % n;
		d *= 2;
		if (x == 1)
			return false;
		if (x == n - 1)
			return true;
	}
	return false;
}
bool isPrime(int n, int k)
{

	if (n <= 1 || n == 4)
		return false;
	if (n <= 3)
		return true;

	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	for (int i = 0; i < k; i++)
		if (!miillerTest(d, n))
			return false;
	return true;
}
int main()
{
	int k;
	cout << "Enter the number of iterations : ";
	cin >> k;
	int t = 1;
	while (t)
	{
		cout << "\nEnter the number : ";
		int n;
		cin >> n;
		if (isPrime(n, k))
			cout << "The number is prime\n";
		else
			cout << "The number is not prime\n";
		int x;
		cout << "press 1 for continue, 0 to exit: ";
		cin >> x;
		t = x;
	}
	return 0;
}
