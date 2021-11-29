#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define pii pair<int, int>
#define nmax 501
using namespace std;

vector<int> v[nmax];
int check[nmax];
int n, m, ans;

void bfs(int cur)
{
	check[cur] = 1;
	queue<int> q;
	q.push(cur);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			if (check[y] == 0)
			{
				check[y] = check[x] + 1;
				q.push(y);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	check[1] = 1;
	bfs(1);

	for (int i = 2; i <= n; i++)
	{
		if (check[i] == 2 || check[i] == 3)
			ans++;
	}
	cout << ans;
}