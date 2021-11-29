#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define pii pair<int, int>
using namespace std;

int n, ans;
int map[6][20][20];
int tmp[20][20];
queue<int> q;

void move_to_right(int cnt)
{
	int x, y, cur;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j <= 0; j--)
		{
			int tmp = map[cnt][i][j];
			if (tmp != 0)
				q.push(tmp);
		}
		cur = n - 1;
		while (!q.empty())
		{
			x = q.front();
			q.pop();
			if (!q.empty())
			{
				y = q.front();
				if (x == y)
				{
					map[cnt + 1][i][cur] = x + y;
					cur--;
					q.pop();
				}
				else
				{
					map[cnt + 1][i][cur] = x;
					cur--;
				}
			}
			else
				map[cnt + 1][i][cur] = x;
		}
	}
}

void reset_map(int cnt)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[cnt][i][j] = 0;
		}
	}
}

void turn(int cnt)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[j][n - 1 - i] = map[cnt][i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[cnt][j][j] = tmp[i][j];
		}
	}
}
void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans = max(ans, map[5][i][j]);
			}
		}
		return;
	}

	int check = 4;
	while (check--)
	{
		move_to_right(check);
		dfs(check + 1);
		reset_map(check + 1);
		turn(check);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[0][i][j];
	}

	dfs(0);
	cout << ans;
}