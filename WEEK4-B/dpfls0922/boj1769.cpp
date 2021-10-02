#include <bits/stdc++.h>
#include <string>
using namespace std;

string changeNum(string n) {
	int sum = 0;
	for (int i = 0; i < n.length(); i++)
		sum += n[i] - '0';
	return to_string(sum);
}

int main() {
	int cnt = 0;
	string n;
	cin >> n;
	while (n.length()!=1) {
		n = changeNum(n);
		cnt++;
	}
	cout << cnt << '\n';
	if (n == "3" || n == "6" || n == "9") cout << "YES";
	else cout << "NO";
	return 0;
}