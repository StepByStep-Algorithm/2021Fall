#include <iostream>
using namespace std;

int main() {
	int T, a, b;
	cin >> T;

	int firstreward[21] = { 500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10, 10, 10, 10, 10 };
	int secondreward[31] = { 512, 256, 256, 128, 128, 128, 128, 64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		if (a > 100) a = 0;
		else a = firstreward[a];
		
		if (b > 64) b = 0;
		else b = secondreward[b];
		
		int sum = (a + b) * 10000;

		cout << sum << endl;
	}
}