#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <stack>
#define ll long long
#define pii pair<int, int>
#define Max(a, b, c) max(a, max(b, c))
#define Min(a, b, c) min(a, min(b, c))
using namespace std;

int maxdp[100001][3];
int mindp[100001][3];
int p[100001][3];
int n, ansmax, ansmin  = INT_MAX;

int findmax(int x, int y)
{
	if (x > n)
		return 0;
	if (maxdp[x][y] != -1)
		return maxdp[x][y];

	int target = findmax(x + 1, y);
	int left, right;
	left = !(y == 0) ? findmax(x + 1, y - 1) : 0;
	right = !(y == 2) ? findmax(x + 1, y + 1) : 0;

	return maxdp[x][y] = p[x][y] + Max(left, target, right);
}

int findmin(int x, int y)
{
	if (x > n)
		return 0;
	if (mindp[x][y] != -1)
		return mindp[x][y];

	int target = findmin(x + 1, y);
	int left, right;
	left = !(y == 0) ? findmin(x + 1, y - 1) : INT_MAX;
	right = !(y == 2) ? findmin(x + 1, y + 1) : INT_MAX;

	return mindp[x][y] = p[x][y] + Min(left, target, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> p[i][j];
		}
	}
	for(int i = 0; i < 3; i++) {
		
	memset(maxdp, -1, sizeof(maxdp));
	memset(mindp, -1, sizeof(mindp));
	ansmax= max(ansmax, findmax(0, i));
	ansmin= min(ansmin, findmin(0, i));
	}

	cout << ansmax << " " << ansmin;
}