#include <bits/stdc++.h>
using namespace std;

int n, row, col;
int ans = 0;

void Z(int r, int c, int size) {

    if (r == row && c == col){
        cout << ans << '\n';
        return;
    }

	if (row >= r && row < r + size && col >= c && col < c + size) {
		Z(r, c, size / 2);
		Z(r, c + size / 2, size / 2);
		Z(r + size / 2, c, size / 2);
		Z(r + size / 2, c + size / 2, size / 2);
	}
	else
		ans += size * size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> row >> col;
	Z(0, 0, (1 << n));

	return 0;
}