#include <iostream>
#include <string>
using namespace std;

long long num_length(int n) {
	long long idx = 0;
	for (int start = 1, i = 1; start < n + 1; start *= 10, ++i) {
		int end = start * 10 - 1;
		if (end > n) {
			end = n;
		}
		idx += (long long)(end - start + 1) * i;
	}
	return idx;
}

int binarySearch(int left, int right, int key) {
	if (left >= right) {
		return right;
	}
	int mid = (left + right) / 2;
	long long idx = num_length(mid);
	// 1���� mid���� ���� ���ο� �� ����<key �� ���
	if (idx < key) {
		return binarySearch(mid + 1, right, key); // [mid+1, right] ������ ��Ž��
	}
	// 1���� mid���� ���� ���ο� �� ����>=key �� ���
	else
		return binarySearch(left, mid, key); // [left,mid) ������ �� Ž��
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, k;

	cin >> n >> k;

	// ���ο� ���� ���̰� k���� ���� ���
	if (num_length(n) < k) {
		cout << -1;
		return 0;
	}
	int i_num = binarySearch(1, n, k);
	int length = num_length(i_num);

	string s_num = to_string(i_num);

	cout << s_num[(s_num.size() - (length - k) - 1)];

	return 0;

}