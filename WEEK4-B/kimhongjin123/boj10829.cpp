#include <iostream>
using namespace std;

void num(long  n)
{
	if (n == 1)
	{
		cout << n;
		return;
	}
	else if (n == 0)
	{
	
		return;
	}
	
	num(n / 2);
	cout << n % 2;
}
int main()
{
	long  n;
	cin >> n;
	num(n);
	
	return 0;
}

