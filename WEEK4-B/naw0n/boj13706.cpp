#include<iostream>
#include<cmath>

using namespace std;

double squareRoot(double N, long double key);
long long N;

int main()
{
	cin >> N;
	long long mid = N / 2;
	cout << squareRoot(N, mid) << endl;
	return 0;
}

double squareRoot(double N, long double key)
{
	long double root = (0.5 * (key + (N / key)));
	if (abs(key - root) >= 0.00000000000001)
		return squareRoot(N, root);
	else
		return root;
}