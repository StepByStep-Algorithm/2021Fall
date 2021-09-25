#include <iostream>
using namespace std;

int main() {
	int T, a, b;
	cin >> T;

	int firstreward[100] = { 500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10, 10, 10, 10, 10 };
	int secondreward[64] = { 512, 256, 256, 128, 128, 128, 128, 64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		int sum = 10000 * (firstreward[a - 1] + secondreward[b - 1]);

		cout << sum << endl;
	}
	return 0;
}