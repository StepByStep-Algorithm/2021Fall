#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m = i, tmp = i;
		while (tmp) {
			m += tmp % 10;
			tmp /= 10;
		}
		if (m == n) {
			cout << i << "\n";
			break;
		}
		if (i == n - 1) cout << "0\n";
	}
	return 0;
}