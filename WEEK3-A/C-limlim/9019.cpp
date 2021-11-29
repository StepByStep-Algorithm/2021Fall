#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define pii pair<int, int>
using namespace std;

char DSLR[4] = {'D', 'S', 'L', 'R'};
int t, a, b;
queue<int> q;

void bfs(int a, int b)
{
	char charpath[10001];
	bool check[10000];
	int numpath[10000];
	q.push(a);
	check[a] = true;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == b)
		{
			vector<char> ans;
			while (x != a)
			{
				ans.push_back(charpath[x]);
				x = numpath[x];
			}
			int len = ans.size();
			for (int i = 0; i < len; i++)
			{
				cout << ans[len - 1 - i];
			}
			cout << "\n";
			return;
		}
		int cal[4] = {(2 * x) % 10000, x - 1, (x % 1000) * 10 + x / 1000, (x % 10) * 1000 + x / 10};
		if (cal[1] < 0)
			cal[1] = 9999;
		for (int i = 0; i < 4; i++)
		{
			if (!check[cal[i]])
			{
				q.push(cal[i]);
				check[cal[i]] = true;
				numpath[cal[i]] = x;
				charpath[cal[i]] = DSLR[i];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		bfs(a, b);
	}
}