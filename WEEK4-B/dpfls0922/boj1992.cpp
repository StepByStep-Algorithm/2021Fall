#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int arr[64][64];

void cutPaper(int x, int y, int size) {
	if (size == 1) {
		if (arr[x][y] == 0) {
			cout << arr[x][y];
			return;
		}
	}
	bool flag = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[x][y] != arr[i][j]) {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		cout << arr[x][y];
		return;
	}
	cout << "(";
	cutPaper(x, y, size / 2);
	cutPaper(x, y + size / 2, size / 2);
	cutPaper(x + size / 2, y, size / 2);
	cutPaper(x + size / 2, y + size / 2, size / 2);
	cout << ")";
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]);

	cutPaper(0, 0, n);

	return 0;
}