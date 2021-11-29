#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#define ll long long
#define nummax 5000010
#define pii pair<int, int>
using namespace std;

int arr[nummax];
int n, l;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> l;
	for(int i = 0; i < n; i++) cin >> arr[i];

	deque<pii> dq;

	for(int i = 0; i < n; i++) {
		if(dq.size() != 0 && dq.front().second <= i - l) dq.pop_front();
		while( !dq.empty() && dq.back().first > arr[i]) dq.pop_back();

		dq.push_back({arr[i], i});
		cout << dq.front().first << " ";
	}

}