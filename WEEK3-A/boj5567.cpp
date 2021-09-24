#include <bits/stdc++.h>

using namespace std;

const unsigned short MAX = 500;

int main()
{
    // 입력 속도 업
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	bool adj[MAX + 1][MAX + 1] = {};
	bool check[MAX + 1] = { true, };
	int n, m, c = 0;
	queue<int> q;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		adj[x - 1][y - 1] = adj[y - 1][x - 1] = true;
	}

	for (int i = 0; i < n; i++)
		if (adj[0][i] && !check[i])
		{
			check[i] = true;
			c++;
			q.push(i);
		}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < n ; i++)
        {

			if (!check[i] && adj[cur][i])
			{
				check[i] = true;
				c++;
			}
        }
	}

	cout << c;

	return 0;
}