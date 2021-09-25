#include <iostream>
#include <string>
using namespace std;

int M, result, Bit;
string input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	while (M--) {
		input.clear();
		cin >> input;

		if (input == "add") {
			cin >> result;
			Bit |= (1 << result);
		}
		else if (input == "remove") {
			cin >> result;
			Bit &= ~(1 << result);
		}
		else if (input == "check") {
			cin >> result;
			if (Bit & (1 << result)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (input == "toggle") {
			cin >> result;
			Bit ^= (1<< result);
		}
		else if (input == "all") {
			Bit = (1 << 21) - 1;
		}
		else if (input == "empty") {
			Bit = 0;
		}
	}
	return 0;
}