#include <iostream>
using namespace std;

int main() {

	int T; // 테스트 케이스 수
	cin >> T;

	while (T--) {
		int n, m; // 국가 수, 비행기 종류
		cin >> n >> m;

		int a, b;
		while (m--) {
			cin >> a >> b;
		}

		cout << n - 1 << endl;
	}
}