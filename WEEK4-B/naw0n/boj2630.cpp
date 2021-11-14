#include <iostream>
using namespace std;
int map[129][129];
int a, b = 0;

void find(int x, int y, int key) {
	int tmp = 0;
	for (int i = x; i < x + key; i++) {
		for (int j = y; j < y + key; j++) {
			if (map[i][j]) tmp++;
		}
	}

	if (!tmp) b++;
	else if (tmp == key * key) a++;
	else {
		find(x, y, key / 2);
		find(x + key / 2, y, key / 2);
		find(x, y + key / 2, key / 2);
		find(x + key / 2, y + key / 2, key / 2);
	}
	return;
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i + 1][j + 1];
		}
	}
	find(1, 1, N);
	cout << b << endl;
	cout << a << endl;
}