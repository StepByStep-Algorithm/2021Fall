#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >>a >> b;
		
			if (a == 1)
			{
				a = 5000000;
			}
			else if (a > 1 && a < 4)
			{
				a = 3000000;
			}
			else if (a > 3 && a < 7)
			{
				a = 2000000;
			}
			else if (a > 6 && a < 11)
			{
				a = 500000;
			}
			else if (a > 10 && a < 16)
			{
				a = 300000;
			}
			else if (a >15  && a < 22)
			{
				a = 100000;
			}
			else
			{
				a = 0;
			}	

		if (b == 1)
		{
			b = 5120000;
		}
		else if (b > 1 && b < 4)
		{
			b = 2560000;
		}
		else if (b > 3 && b < 8)
		{
			b = 1280000;
		}
		else if (b > 7 && b < 16)
		{
			b = 640000;
		}
		else if (b > 15 && b < 32)
		{
			b = 320000;
		}
		else
		{
			b = 0;
		}

		cout << a + b<<'\n';
		
	}
}

