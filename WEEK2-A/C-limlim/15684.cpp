#include <iostream>
#include <cstring>
#include <limits.h>
#include <string>
#include <vector>
#include <stack>
#define ll long long
#define pii pair<int, int>
using namespace std;

int n, m, h, ans = INT_MAX;
bool ladder[11][30];

bool do_ladder()
{
	for (int i = 1; i <= n; i++)
	{
		int checkflag = i;
		for (int j = 1; j <= h; j++)
		{
			if (ladder[checkflag][j])
				checkflag++;
			else if (ladder[checkflag - 1][j])
				checkflag--;
		}

		if (checkflag != i)
			return false;
	}
	return true;
}

void dp(int cnt, int index)
{

	if (do_ladder())
	{
		ans = min(ans, cnt);
		return;
	}
	if (cnt > 4)
		return;

	for (int i = index; i <= h; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (ladder[j - 1][i] == true)
				continue;
			if (ladder[j][i] == true)
				continue;
			if (ladder[j + 1][i] == true)
				continue;

			ladder[j][i] = true;
			dp(i, cnt + 1);
			ladder[j][i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int x, y;
	cin >> x >> y;
	ladder[y][x] = true;

	dp(0, 1);

	if (ans = INT_MAX)
		ans = -1;
	cout << ans;
}