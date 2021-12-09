#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[101];
	int n, m, sum = 0, min = 9999999, answer;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = a[i] + a[j] + a[k];
				if (m - sum >= 0 && m - sum < min) {
					min = m - sum;
					answer = sum;
				}
			}
		}
	}
	cout << answer;	
	return 0;
}