#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#define ll long long
#define pii pair<int, int>
using namespace std;

stack<pii> s;
ll ans = 0;
int n, x;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;

	while (n--)
	{
		cin >> x;
		while(s.size() != 0 && s.top().first < x) {
			ans += s.top().second;
			s.pop();
		}

		pii tmp;
		tmp.first = x; tmp.second = 1;

		if(s.size() != 0 && s.top().first == x) {
			tmp.second += s.top().second;
			ans += s.top().second;
			s.pop();
		}

		if(s.size() != 0) ans++;
		s.push(tmp);
	}

	cout << ans;
}