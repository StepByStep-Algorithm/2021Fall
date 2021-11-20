#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v(8, 0);
vector<int> result;

void fun(int cnt, int start) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << result[v[i]] << " ";
		cout << "\n";
	}
	else {
		for (int i = start; i < n; i++) {
			v[cnt] = i;
			fun(cnt + 1, i);
		}
	}
}

int main() {
	int num;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num;
		result.push_back(num);
	}
	sort(result.begin(), result.end());
	fun(0, 0);

	return 0;
}