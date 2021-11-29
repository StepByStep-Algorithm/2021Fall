#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#define ll long long
#define pii pair<int, int>
using namespace std;

int dp[30];
int n, day, cost;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] > dp[i + 1])
			dp[i + 1] = dp[i];

		if (dp[i] + cost < dp[i + day])
			dp[i + day] = dp[i] + cost;
	}

	cout << dp[n];
}