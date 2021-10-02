#include <iostream>
using namespace std;

void Binaryto(long long n) {
	if (n != 1) Binaryto(n / 2);
	cout << (n % 2);
}
int main() {
	long long N;
	cin >> N;

	Binaryto(N);
	cout << endl;

	return 0;
}