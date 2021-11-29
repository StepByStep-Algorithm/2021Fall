#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#define ll long long
#define pii pair<int, int>
using namespace std;

int n, m, book[10001], ans;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> book[i];

	sort(book, book + n + 1);

	// 0인 지점 구하기
	int idx = 0;
	for (int i = 0; i <= n; ++i)
	{
		if (book[i] == 0)
		{
			idx = i;
			break;
		}
	}

	for (int i = 0; i < idx; i += m)
		ans += abs(book[i] * 2);

	for (int i = n; i > idx; i -= m)
		ans += book[i] * 2;

	ans -= max(abs(book[0]), abs(book[n]));

	cout << ans;
}