#include <iostream>
#define N 5

long long x[N][N];
long long y[N][N];
long long tmp[N][N];
long long b;
int n;

using namespace std;

void mul(long long a[N][N], long long p[N][N])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				tmp[i][j] += a[i][k] * p[k][j];
			}
			tmp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[i][j] = tmp[i][j];
		}
	}
}

void do_(long long t)
{
	if (t == 1)
		return;

	if (t % 2 == 0)
	{

		do_(t / 2);
		mul(x, x);
	}
	else if (t % 2 == 1)
	{

		do_(t / 2);
		mul(x, x);
		mul(x, y);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> x[i][j];
			x[i][j] %= 1000;
			y[i][j] = x[i][j];
		}
	}

	do_(b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}