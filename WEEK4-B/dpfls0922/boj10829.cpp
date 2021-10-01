#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	long long n;
	vector<int> binary;
	cin >> n;
	while (n) {
		binary.push_back(n % 2);
		n /= 2;
	}
	for (int i = binary.size()-1; i >= 0; i--) {
		cout << binary[i];
	}
}