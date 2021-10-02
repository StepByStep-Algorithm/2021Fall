#include <iostream>
#include <string>
using namespace std;
bool map[65][65];
string input;

void find(int x, int y, int n) {
	int tmp = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (map[i][j]) tmp++;
		}
	}

	if (tmp == n * n) cout << 1;
	else if (!tmp) cout << 0;
	else {
		cout << "(";
		find(x, y, n / 2);
		find(x, y + n / 2, n / 2);
		find(x + n / 2, y, n / 2);
		find(x + n / 2, y + n / 2, n / 2);
		cout << ")";
	}
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			map[i+1][j+1] = input[j] - '0';
		}
	}

	find(1, 1, N);
	return 0;
}