#include <iostream>
#include <string>
using namespace std;

int main() {
	string x;
	cin >> x;
	int i = 0;

	while (int(x.size()) != 1) {
		int sum = 0;
		for (unsigned i = 0; i < x.size(); i++) {
			sum += int(x[i]) - 48;
		}
		x = to_string(sum);
		i++;
	}

	cout << i << '\n';
	if (x == "3" || x == "6" || x == "9")
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}
