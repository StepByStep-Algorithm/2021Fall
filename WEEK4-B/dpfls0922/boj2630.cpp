#include <bits/stdc++.h>
using namespace std;

int arr[128][128];
int white, blue;

void cutPaper(int x, int y, int size) {
	if (size == 1){
		if (arr[x][y] == 0) white++;
		else blue++;
		return;
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
		if (arr[x][y] == 0) white++;
		else blue++;
		return;
	}
	cutPaper(x, y, size / 2);
	cutPaper(x + size / 2, y, size / 2);
	cutPaper(x, y + size / 2, size / 2);
	cutPaper(x + size / 2, y + size / 2, size / 2);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	cutPaper(0, 0, n);
	cout << white << '\n';
	cout << blue << '\n';

	return 0;
}