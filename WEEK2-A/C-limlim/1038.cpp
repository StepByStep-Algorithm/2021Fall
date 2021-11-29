#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#define ll long long
#define nummax 100001
#define pii pair<int, int>
using namespace std;

ll savenum[nummax];
int n, curr = 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	if (n >= 1023) {
		cout << "-1";
		return 0;
	}

	for(int i = 0; i < 10; i ++) savenum[i] = i;
	for(int i = 1; i <= n; i++) {
		for(int j =0; j < (savenum[i] % 10); j++) {
			savenum[curr] = savenum[i] * 10 + j;
			curr++;
		}
	}

	cout << savenum[n];
}