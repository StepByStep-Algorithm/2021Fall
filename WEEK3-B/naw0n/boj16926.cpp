#include <iostream>
using namespace std;
int n, m, r, arr[301][301];

void rotation() {
	int tmp[301][301];
	for (int angle = 0; angle < min(n, m) / 2; angle++) {
		int x1 = angle, y1 = angle, x2 = n - angle - 1, y2 = m - angle - 1; 
		for (int i = y2 - 1; i >= y1; i--) tmp[x1][i] = arr[x1][i + 1]; // аб
		for (int i = x1 + 1; i <= x2; i++) tmp[i][y1] = arr[i - 1][y1]; //го
		for (int i = y1 + 1; i <= y2; i++) tmp[x2][i] = arr[x2][i - 1]; //©Л
		for (int i = x2 - 1; i >= x1; i--) tmp[i][y2] = arr[i + 1][y2]; // ╩С
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
	}
}

int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (r--) rotation();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}